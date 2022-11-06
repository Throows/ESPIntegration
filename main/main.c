#include <stdio.h>
#include "esp_timer.h"
#include "Data.h"
#include "IntegrateFunc.h"
const char *TAG = "Integral";


const char *func_name[] = {"eff_left", "eff_right", "eff_trap", "mean_left", "mean_right", "mean_trap", "mean"};
const integrate_f_fc f_func[] = {&eff_left_sum, &eff_right_sum, &eff_trapz_rule, &mean_left_sum, &mean_right_sum, &mean_trapz_rule, &mean};
const integrate_d_fc d_func[] = {&eff_left_sum_d, &eff_right_sum_d, &eff_trapz_rule_d, &mean_left_sum_d, &mean_right_sum_d, &mean_trapz_rule_d, &mean_d};

#define MAX_TEST 7 

void monitorTimeF(const char *fc_name, integrate_f_fc fc)
{
    float result = 0;
    uint64_t start = esp_timer_get_time();

    for (int i = 0; i < MEASURE_NB; i++)
        result = fc();
    
    uint64_t end = esp_timer_get_time();

    ESP_LOGI(TAG, "%s took %llu ms, (%llu us/call)", fc_name, (end - start) / 1000, (end - start) / MEASURE_NB);
    ESP_LOGI(TAG, "Returned %.2f", result);
}

void monitorTimeD(const char *fc_name, integrate_d_fc fc)
{
    ESP_LOGI(TAG, "Starting time report for %s ", fc_name);
    float result = 0;
    uint64_t start = esp_timer_get_time();

    for (int i = 0; i < MEASURE_NB; i++)
        result = fc();

    uint64_t end = esp_timer_get_time();

    ESP_LOGI(TAG, "%d function call took %llu ms, (%llu microseconds per invocation)", MEASURE_NB, (end - start) / 1000, (end - start) / MEASURE_NB);
    ESP_LOGI(TAG, "Result : %.2f", result);
}

void app_main(void)
{
    esp_log_level_set("*", ESP_LOG_DEBUG);
    /* Fill datas */
    setup();
    make_rect_two();
    ESP_LOGI(TAG, "Functions created Sucessfully !");
    ESP_LOGI(TAG, "Sampling rate is %.2f Hz (%.4f ms), the period measure is %.4f s", SAMPLING_FREQ, DELTA_X*1000, MEASURE_PERIOD);
    ESP_LOGI(TAG, "Determinate execution time after %d calls", MEASURE_NB);
    for (uint8_t i = 0; i < MAX_TEST; i++)
    {
        ESP_LOGW(TAG, "--- FLOAT ---");
        monitorTimeF(func_name[i], f_func[i]);
        /*ESP_LOGW(TAG, "--- DOUBLE ---");
        monitorTimeD(double_func_name[i], d_func[i]);*/
    }

    ESP_LOGI(TAG, "Done !");
    
    for(;;)
        vTaskDelay(pdMS_TO_TICKS(1000));
    
}