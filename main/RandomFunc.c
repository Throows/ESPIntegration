#include "RandomFunc.h"

void makeRandom()
{
    random_data = (float *)malloc(sizeof(float) * NB_MEASURE);
    uint16_t random = 0;
    for (int i = 0; i < NB_MEASURE; i++)
    {
        esp_fill_random(&random, 2);
        random_data[i] = (random % 51) + 50;
    }
}