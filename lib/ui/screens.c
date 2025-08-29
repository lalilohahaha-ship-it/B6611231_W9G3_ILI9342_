#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // adc_chart
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.adc_chart = obj;
            lv_obj_set_pos(obj, 0, 85);
            lv_obj_set_size(obj, 206, 155);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171515), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 212, 195);
            lv_obj_set_size(obj, 100, 34);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // nextpage_bt
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.nextpage_bt = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Next Page");
                }
            }
        }
        {
            // adc34bar
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.adc34bar = obj;
            lv_obj_set_pos(obj, 62, 63);
            lv_obj_set_size(obj, 172, 13);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
        }
        {
            // adc33bar
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.adc33bar = obj;
            lv_obj_set_pos(obj, 62, 38);
            lv_obj_set_size(obj, 172, 13);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 0, 38);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ADC33");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 0, 63);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ADC34");
        }
        {
            // adc33val
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.adc33val = obj;
            lv_obj_set_pos(obj, 244, 37);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0");
        }
        {
            // adc34val
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.adc34val = obj;
            lv_obj_set_pos(obj, 244, 62);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 195, 8);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "B6611231 Aililla S.");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 239, 103);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ADC33");
        }
        {
            // adc33led
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.adc33led = obj;
            lv_obj_set_pos(obj, 247, 131);
            lv_obj_set_size(obj, 32, 32);
            lv_led_set_color(obj, lv_color_hex(0xff25ff00));
            lv_led_set_brightness(obj, 255);
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}

void create_screen_control_page() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.control_page = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 13, 9);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "PWM Control");
        }
        {
            // home_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.home_bt = obj;
            lv_obj_set_pos(obj, 13, 200);
            lv_obj_set_size(obj, 72, 32);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Home");
                }
            }
        }
        {
            // onmotor_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.onmotor_bt = obj;
            lv_obj_set_pos(obj, 14, 104);
            lv_obj_set_size(obj, 117, 35);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff20b419), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Open Motor");
                }
            }
        }
        {
            //  offmotor_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects._offmotor_bt = obj;
            lv_obj_set_pos(obj, 14, 150);
            lv_obj_set_size(obj, 117, 33);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd76a15), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Closed Motor");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 13, 80);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Pump Control");
        }
        {
            // decrementpwm
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.decrementpwm = obj;
            lv_obj_set_pos(obj, 14, 39);
            lv_obj_set_size(obj, 35, 31);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff32121), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "-");
                }
            }
        }
        {
            //  incrementpwm
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects._incrementpwm = obj;
            lv_obj_set_pos(obj, 143, 39);
            lv_obj_set_size(obj, 35, 31);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff398c0a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "+");
                }
            }
        }
        {
            // pwmval
            lv_obj_t *obj = lv_spinbox_create(parent_obj);
            objects.pwmval = obj;
            lv_obj_set_pos(obj, 62, 37);
            lv_obj_set_size(obj, 71, 34);
            lv_spinbox_set_digit_format(obj, 3, 0);
            lv_spinbox_set_range(obj, 0, 255);
            lv_spinbox_set_rollover(obj, false);
            lv_spinbox_set_step(obj, 1);
            lv_spinbox_set_value(obj, 0);
        }
        {
            // onpwm_sw
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.onpwm_sw = obj;
            lv_obj_set_pos(obj, 228, 42);
            lv_obj_set_size(obj, 50, 25);
        }
        {
            // fan_led
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.fan_led = obj;
            lv_obj_set_pos(obj, 237, 150);
            lv_obj_set_size(obj, 32, 32);
            lv_led_set_color(obj, lv_color_hex(0xff0000ff));
            lv_led_set_brightness(obj, 255);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 190, 46);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "OFF");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 289, 46);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "ON");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 239, 120);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FAN");
        }
    }
    
    tick_screen_control_page();
}

void tick_screen_control_page() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_control_page,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_control_page();
}
