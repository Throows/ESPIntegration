#ifndef DATA_H
#define DATA_H

#include <math.h>
#include <stdio.h>
#include "esp_random.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task_wdt.h"

#define MEASURE_NB 5000
#define FUNC_FREQ 5
#define SAMPLING_FREQ 1000.0
#define DELTA_X (float)(1.0 / SAMPLING_FREQ)
#define NB_MEASURE 512.0
#define PI 3.1416
#define MEASURE_PERIOD (float)(DELTA_X * NB_MEASURE)

#endif // DATA_H