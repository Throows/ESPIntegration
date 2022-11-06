#include "IntegrateFunc.h"

/* FLOAT usage */
float eff_left_sum()
{
    /* 
     * Formula : A = sqrt( DeltaX * sum(measures * measure) )
     * This formula is true only if Delta between measure is the same
    */
    float integration = 0;

    /* Left method take the first and the last - 1 */
    for (int i = 0; i < NB_MEASURE - 1; i++)
    {
        integration += data_f[i] * data_f[i];
    }
    integration *= DELTA_X;
    return sqrtf( integration / MEASURE_PERIOD );
}

float eff_right_sum()
{
    /*
     * Formula : A = DeltaX * sum(measures)
     * This formula is true only if Delta between measure is the same
     */
    float integration = 0;

    /* right method take the second point and the last point */
    for (int i = 1; i < NB_MEASURE; i++)
    {
        integration += data_f[i] * data_f[i];
    }
    integration *= DELTA_X;
    return sqrtf( integration / MEASURE_PERIOD );
}

float eff_midpoint_rule()
{
    /*
     * Formula : A = DeltaX * sum(measures)
     * This formula is true only if Delta between measure is the same
     */
    /* midpoint method take the first point and the last - 1 point */

    /* Midpoint rule is not implemented cuz it can't be calculated with a bunch of points (no function) */
    return 0;
}

float eff_trapz_rule()
{
    /*
     * Formula : A = DeltaX * sum([measures+(measure+1)]/2)
     * This formula is true only if Delta between measure is the same (UNIFORM)
     */
    float integration = 0;
    const uint64_t last = NB_MEASURE - 1;

        for (int i = 1; i < NB_MEASURE; i++)
    {
        integration += data_f[i] * data_f[i];
    }
    integration += ((data_f[0] * data_f[0]) + (data_f[last] * data_f[last])) / 2.0;
    integration *= DELTA_X;
    return sqrtf(integration / MEASURE_PERIOD);
}


float mean_left_sum()
{
    /*
     * Formula : A = DeltaX * sum(measures)
     * This formula is true only if Delta between measure is the same
     */
    float integration = 0;

    /* Left method take the first and the last - 1 */
    for (int i = 0; i < NB_MEASURE - 1; i++)
    {
        integration += data_f[i];
    }
    integration *= DELTA_X;
    return integration / MEASURE_PERIOD;
}

float mean_right_sum()
{
    /*
     * Formula : A = DeltaX * sum(measures)
     * This formula is true only if Delta between measure is the same
     */
    float integration = 0;

    /* right method take the second point and the last point */
    for (int i = 1; i < NB_MEASURE; i++)
    {
        integration += data_f[i];
    }
    integration *= DELTA_X;
    return integration / MEASURE_PERIOD;
}

float mean_midpoint_rule()
{
    /*
     * Formula : A = DeltaX * sum(measures)
     * This formula is true only if Delta between measure is the same
     */
    /* midpoint method take the first point and the last - 1 point */

    /* Midpoint rule is not implemented cuz it can't be calculated with a bunch of points (no function) */
    return 0;
}

float mean_trapz_rule()
{
    /*
     * Formula : A = DeltaX * sum([measures+(measure+1)]/2)
     * This formula is true only if Delta between measure is the same (UNIFORM)
     */
    float integration = 0;
    const uint64_t last = NB_MEASURE - 1;

    for (int i = 1; i < NB_MEASURE; i++)
    {
        integration += data_f[i];
    }
    integration += (data_f[0] + data_f[last]) / 2.0;
    integration *= DELTA_X;
    return integration / MEASURE_PERIOD;
}


float mean()
{
    float mean = 0;
    for (int i = 0; i < NB_MEASURE; i++)
    {
        mean += data_f[i];
    }
    return mean / NB_MEASURE;
}

/* DOUBLE usage */
double eff_left_sum_d()
{
    /*
     * Formula : A = sqrt( DeltaX * sum(measures * measure) )
     * This formula is true only if Delta between measure is the same
     */
    double integration = 0;

    /* Left method take the first and the last - 1 */
    for (int i = 0; i < NB_MEASURE - 1; i++)
    {
        integration += data_d[i] * data_d[i];
    }
    integration *= DELTA_X;
    return sqrt(integration / MEASURE_PERIOD);
}

double eff_right_sum_d()
{
    /*
     * Formula : A = DeltaX * sum(measures)
     * This formula is true only if Delta between measure is the same
     */
    double integration = 0;

    /* right method take the second point and the last point */
    for (int i = 1; i < NB_MEASURE; i++)
    {
        integration += data_d[i] * data_d[i];
    }
    integration *= DELTA_X;
    return sqrt(integration / MEASURE_PERIOD);
}

double eff_midpoint_rule_d()
{
    /*
     * Formula : A = DeltaX * sum(measures)
     * This formula is true only if Delta between measure is the same
     */
    /* midpoint method take the first point and the last - 1 point */

    /* Midpoint rule is not implemented cuz it can't be calculated with a bunch of points (no function) */
    return 0;
}

double eff_trapz_rule_d()
{
    /*
     * Formula : A = DeltaX * sum([measures+(measure+1)]/2)
     * This formula is true only if Delta between measure is the same (UNIFORM)
     */
    double integration = 0;
    const uint64_t last = NB_MEASURE - 1;

    for (int i = 1; i < NB_MEASURE; i++)
    {
        integration += data_d[i] * data_d[i];
    }
    integration += ((data_d[0] * data_d[0]) + (data_d[last] * data_d[last])) / 2.0;
    integration *= DELTA_X;
    return sqrt(integration / MEASURE_PERIOD);
}


double mean_left_sum_d()
{
    /*
     * Formula : A = DeltaX * sum(measures)
     * This formula is true only if Delta between measure is the same
     */
    double integration = 0;

    /* Left method take the first and the last - 1 */
    for (int i = 0; i < NB_MEASURE - 1; i++)
    {
        integration += data_d[i];
    }
    integration *= DELTA_X;
    return integration / MEASURE_PERIOD;
}

double mean_right_sum_d()
{
    /*
     * Formula : A = DeltaX * sum(measures)
     * This formula is true only if Delta between measure is the same
     */
    double integration = 0;

    /* right method take the second point and the last point */
    for (int i = 1; i < NB_MEASURE; i++)
    {
        integration += data_d[i];
    }
    integration *= DELTA_X;
    return integration / MEASURE_PERIOD;
}

double mean_midpoint_rule_d()
{
    /*
     * Formula : A = DeltaX * sum(measures)
     * This formula is true only if Delta between measure is the same
     */
    /* midpoint method take the first point and the last - 1 point */

    /* Midpoint rule is not implemented cuz it can't be calculated with a bunch of points (no function) */
    return 0;
}

double mean_trapz_rule_d()
{
    /*
     * Formula : A = DeltaX * sum([measures+(measure+1)]/2)
     * This formula is true only if Delta between measure is the same (UNIFORM)
     */
    double integration = 0;
    const uint64_t last = NB_MEASURE - 1;

    for (int i = 1; i < NB_MEASURE; i++)
    {
        integration += data_d[i];
    }
    integration += (data_d[0] + data_d[last]) / 2.0;
    integration *= DELTA_X;
    return integration / MEASURE_PERIOD;
}


double mean_d()
{
    double mean = 0;
    for (int i = 0; i < NB_MEASURE; i++)
    {
        mean += data_d[i];
    }
    return mean / NB_MEASURE;
}