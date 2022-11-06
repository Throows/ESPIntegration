#include "TwoRectifiedFunc.h"

void makeRectifiedTwo()
{
    rectified_ac_two = (float *)malloc(sizeof(float) * NB_MEASURE);
    for (int i = 0; i < NB_MEASURE; i++)
    {
        rectified_ac_two[i] = abs(20 * cos(2 * PI * FUNC_FREQ * (1 / SAMPLING_FREQ) * i));
    }
}