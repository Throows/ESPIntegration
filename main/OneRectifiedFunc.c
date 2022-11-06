#include "OneRectifiedFunc.h"

void makeRectifiedOne()
{
    rectified_ac_one = (float *)malloc(sizeof(float) * NB_MEASURE);
    for (int i = 0; i < NB_MEASURE; i++)
    {
        float value = 20 * cos(2 * PI * FUNC_FREQ * (1 / SAMPLING_FREQ) * i);
        rectified_ac_one[i] = (value > 0) ? value : 0;
    }
}