#include "Data.h"

void setup()
{
    if (data_f == NULL)
        data_f = (float *)malloc(sizeof(float) * NB_MEASURE);
    else 
        data_f = (float*) realloc(data_f, sizeof(float) * NB_MEASURE);

    if (data_d == NULL)
        data_d = (double *)malloc(sizeof(double) * NB_MEASURE);
    else 
        data_d = (double*) realloc(data_d, sizeof(double) * NB_MEASURE);
}

void make_cos_data()
{
    for (int i = 0; i < NB_MEASURE; i++)
    {
        data_f[i] = (float) 20.0 * cos(2.0 * PI * FUNC_FREQ * (1.0 / SAMPLING_FREQ) * i);
        data_d[i] = (double) 20.0 * cos(2.0 * PI * FUNC_FREQ * (1.0 / SAMPLING_FREQ) * i);
    }
}

void make_rand_data()
{
    uint16_t random = 0;
    for (int i = 0; i < NB_MEASURE; i++)
    {
        esp_fill_random(&random, 2);
        data_f[i] = (float) (random % 51) + 50;
        data_d[i] = (double) (random % 51) + 50;
    }
}

void make_rect_one()
{
    for (int i = 0; i < NB_MEASURE; i++)
    {
        float value = 20 * cos(2 * PI * FUNC_FREQ * (1 / SAMPLING_FREQ) * i);
        data_f[i] = (float) (value > 0) ? value : 0;
        data_d[i] = (double) (value > 0) ? value : 0;
    }
}

void make_rect_two()
{
    for (int i = 0; i < NB_MEASURE; i++)
    {
        data_f[i] = (float) abs(20 * cos(2 * PI * FUNC_FREQ * (1 / SAMPLING_FREQ) * i));
        data_d[i] = (double) abs(20 * cos(2 * PI * FUNC_FREQ * (1 / SAMPLING_FREQ) * i));
    }
}