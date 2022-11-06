#ifndef __DATA_H__
#define __DATA_H__

#include <math.h>
#include <stdio.h>
#include "esp_random.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task_wdt.h"

#define PI 3.141592

#define MEASURE_NB 5000
#define NB_MEASURE 512.0
#define SAMPLING_FREQ 1000.0
#define DELTA_X (float)(1.0 / SAMPLING_FREQ)
#define MEASURE_PERIOD (float)(DELTA_X * NB_MEASURE)

float *data_f;
double *data_d;

void setup();

/* COS function settings */
#define FUNC_FREQ 1

void make_cos_data();

/* Random function Settings */
void make_rand_data();

/* Rectified Function type one */
void make_rect_one();

/* Rectified Function type two */
void make_rect_two();

#endif // __DATA_H__