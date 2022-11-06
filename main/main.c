#include <stdio.h>
#include "esp_timer.h"
#include "Data.h"
#include "esp_log.h"

#include "IntegrateFunc.h"

void app_main(void)
{
    esp_log_level_set("*", ESP_LOG_DEBUG);
    /* Fill datas */
    setup();
    make_cos_data();
    ESP_LOGI("Functions", "Functions created Sucessfully !");
    ESP_LOGI("Parameters", "Using Sampling %.2f (%f ms), the period measure is %f", SAMPLING_FREQ, DELTA_X, MEASURE_PERIOD);
    
    ESP_LOGI("Integrations", "Starting calculations...");
    float result = 0;
    uint64_t start = esp_timer_get_time();

    for (int i = 0; i < MEASURE_NB; i++)
    {
        result = eff_trapz_rule();
    }

    uint64_t end = esp_timer_get_time();

    ESP_LOGI("TIME", "%d function call took %llu ms, (%llu microseconds per invocation)", MEASURE_NB, (end - start) / 1000, (end - start) / MEASURE_NB);
    ESP_LOGI("Result", "%.2f", result);
    /* TODO: show formula accuracy */

    for(;;)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}