#include "CosFunc.h"

void makeCos()
{
    cos_data = (float *)malloc(sizeof(float) * NB_MEASURE);
    for (int i = 0; i < NB_MEASURE; i++)
    {
        cos_data[i] = 20.0 * cos(2.0 * PI * FUNC_FREQ * (1.0 / SAMPLING_FREQ) * i);
    }

    cos_data_d = (double *)malloc(sizeof(double) * NB_MEASURE);
    for (int i = 0; i < NB_MEASURE; i++)
    {
        cos_data_d[i] = 20.0 * cos(2.0 * PI * FUNC_FREQ * (1.0 / SAMPLING_FREQ) * i);
    }
}

/* FLOAT usage */
float cos_eff_left_sum()
{
    /* 
     * Formula : A = sqrt( DeltaX * sum(measures * measure) )
     * This formula is true only if Delta between measure is the same
    */
    float integration = 0;

    /* Left method take the first and the last - 1 */
    for (int i = 0; i < NB_MEASURE - 1; i++)
    {
        integration += cos_data[i] * cos_data[i];
    }
    integration *= DELTA_X;
    return sqrtf(integration / MEASURE_PERIOD);
}

float cos_eff_right_sum()
{
    /*
     * Formula : A = DeltaX * sum(measures)
     * This formula is true only if Delta between measure is the same
     */
    int64_t integration = 0;

    /* right method take the second point and the last point */
    for (int i = 1; i < NB_MEASURE; i++)
    {
        integration += cos_data[i] * cos_data[i];
    }
    integration *= DELTA_X;
    return sqrt( integration / MEASURE_PERIOD);
}

float cos_eff_midpoint_rule()
{
    /*
     * Formula : A = DeltaX * sum(measures)
     * This formula is true only if Delta between measure is the same
     */
    /* midpoint method take the first point and the last - 1 point */

    /* Midpoint rule is not implemented cuz it can't be calculated with a bunch of points (no function) */
    return 0;
}

float cos_eff_trapz_rule()
{
    return 0;
}


float cos_max_left_sum()
{
    return 0;
}

float cos_max_right_sum()
{
    return 0;
}

float cos_max_midpoint_rule()
{
    return 0;
}

float cos_max_trapz_rule()
{
    return 0;
}


float cos_mean()
{
    int64_t mean = 0;
    for (int i = 0; i < NB_MEASURE; i++)
    {
        mean += cos_data[i];
    }
    return mean / NB_MEASURE;
}

/* DOUBLE usage */
double cos_eff_left_sum_d()
{
    /*
     * Formula : A = sqrt( DeltaX * sum(measures * measure) )
     * This formula is true only if Delta between measure is the same
     */
    double integration = 0;

    /* Left method take the first and the last - 1 */
    for (int i = 0; i < NB_MEASURE - 1; i++)
    {
        integration += cos_data[i] * cos_data[i];
    }
    integration *= DELTA_X;
    return sqrtf(integration / MEASURE_PERIOD);
}

double cos_eff_right_sum_d();
double cos_eff_midpoint_rule_d();
double cos_eff_trapz_rule_d();

double cos_max_left_sum_d();
double cos_max_right_sum_d();
double cos_max_midpoint_rule_d();
double cos_max_trapz_rule_d();

double cos_mean_d();