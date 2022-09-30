/*
 * SPDX-FileCopyrightText: 2021 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* ADC1 Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdlib.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "AnalogInput.h"
#include "driver/gpio.h"
#include "stdint.h"


#define LED_GPIO_OUTPUT_IO_0    21
//#define BUTTON_GPIO_INPUT_IO_0     4
//#define GPIO_INPUT_PIN_SEL  ((1ULL<<BUTTON_GPIO_INPUT_IO_0))
//#define ESP_INTR_FLAG_DEFAULT 0

// initialize variable that determines led_level to 0
static uint32_t led_level = 0;

void gpioInit(void);

void app_main(void)
{

    analogReadInit();
    gpioInit();
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(100));
        led_level = !led_level;
        gpio_set_level(LED_GPIO_OUTPUT_IO_0, led_level);
    }
}
void gpioInit(void) {

// configure button
/*
    gpio_config_t io_conf;
    //interrupt of falling edge
    io_conf.intr_type = GPIO_INTR_NEGEDGE;
    //bit mask of the pins, use GPIO4/5 here
    io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
    //set as input mode    
    io_conf.mode = GPIO_MODE_INPUT;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //enable pull-up mode
    io_conf.pull_up_en = 1;
    gpio_config(&io_conf);
    */
    // configure LED
    gpio_pad_select_gpio(LED_GPIO_OUTPUT_IO_0);
    // Set the GPIO as a push/pull output
    gpio_set_direction(LED_GPIO_OUTPUT_IO_0, GPIO_MODE_OUTPUT);
    // start out with LED off
    gpio_set_level(LED_GPIO_OUTPUT_IO_0, led_level);

}
