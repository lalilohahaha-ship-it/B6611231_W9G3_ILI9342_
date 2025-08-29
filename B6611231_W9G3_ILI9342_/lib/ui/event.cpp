#include "event.h"
#include <Arduino.h>

lv_chart_series_t *adc33_chart_data33;
lv_chart_series_t *adc34_chart_data34;

void adcread_event(lv_timer_t *timer)
{
    LV_UNUSED(timer);

    int adc33_raw = analogRead(33);
    int adc34_raw = analogRead(34);

    int adc33pwm = (adc33_raw / 4095.0) * 255.0;
    int adc33_10bit = (adc33_raw / 4095.0) * 1023.0;
    int adc34_10bit = (adc34_raw / 4095.0) * 1023.0;

    lv_bar_set_value(objects.adc33bar, adc33_raw, LV_ANIM_OFF);
    lv_bar_set_value(objects.adc34bar, adc34_raw, LV_ANIM_OFF);
    lv_label_set_text(objects.adc33val, String(analogRead(33)).c_str());
    lv_label_set_text(objects.adc34val, String(analogRead(34)).c_str());
    lv_chart_set_next_value(objects.adc_chart, adc33_chart_data33, adc33_10bit);
    lv_chart_set_next_value(objects.adc_chart, adc34_chart_data34, adc34_10bit);

    lv_led_set_brightness(objects.adc33led, adc33pwm);
}

void adc_chart()
{
    int pointcount = 50;
    int min_value = 0;
    int max_value = 1023;
    // Set type of the chart
    lv_chart_set_type(objects.adc_chart, LV_CHART_TYPE_LINE);
    // Set the number of points on the chart
    lv_chart_set_point_count(objects.adc_chart, pointcount);
    // Set the range of the Y axis
    lv_chart_set_range(objects.adc_chart, LV_CHART_AXIS_PRIMARY_Y, min_value, max_value);
    // Create a data series for the chart
    adc33_chart_data33 = lv_chart_add_series(objects.adc_chart, lv_color_hex(0x0000FF), LV_CHART_AXIS_PRIMARY_Y);
    adc34_chart_data34 = lv_chart_add_series(objects.adc_chart, lv_color_hex(0xFFA500), LV_CHART_AXIS_PRIMARY_Y);
}

void switch_event(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    if (obj == objects.nextapge_bt && code == LV_EVENT_CLICKED)
    {
        lv_scr_load(objects.control_page);
    }
    else if (obj == objects.home_bt && code == LV_EVENT_CLICKED)
    {
        lv_scr_load(objects.main);
    }
}

void led_event(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    int *pLED = (int *)lv_event_get_user_data(e);
    if (obj == objects.onmotor_bt && code == LV_EVENT_CLICKED)
    {
        gpio_set_level((gpio_num_t)*pLED, 1);
    }
    else if (obj == objects.offmotor_bt && code == LV_EVENT_CLICKED)
    {
        gpio_set_level((gpio_num_t)*pLED, 0);
    }
}

void valuechange_event(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    int val = lv_spinbox_get_value(objects.pwmval);
    if (obj == objects.decrementpwm && code == LV_EVENT_PRESSED && val > 0)
    {
        lv_spinbox_set_value(objects.pwmval, val - 1);
    }
    else if (obj == objects.incrementpwm && code == LV_EVENT_RELEASED && val < 255)
    {
        lv_spinbox_set_value(objects.pwmval, val + 1);
    }
}

void get_value(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    if (obj == objects.onpwm_sw)
    {
        if (lv_obj_has_state(objects.onpwm_sw, LV_STATE_CHECKED))
        {
            int val = lv_spinbox_get_value(objects.pwmval);
            analogWrite(22, val);
            Serial.println("PWMVAL:" + String(val));
        }
        else
        {
            analogWrite(22, 0);
        }
    }
}

void get_sw_state(lv_timer_t *timer)
{
    LV_UNUSED(timer);
    int *pSW = (int *)timer->user_data;
    // Serial.println(*pSW);

    if (digitalRead(*pSW) == 0)
    {

        lv_led_on(objects.fan_led);
    }
    else if (digitalRead(*pSW) == 1)
    {
        lv_led_off(objects.fan_led);
    }
}