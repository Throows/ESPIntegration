#ifndef __COS_FUNC_H__
#define __COS_FUNC_H__
#include "Data.h"
 
float *cos_data;
double *cos_data_d;

void makeCos();

/* FLOAT usage */
float cos_eff_left_sum();
float cos_eff_right_sum();
float cos_eff_midpoint_rule();
float cos_eff_trapz_rule();

float cos_max_left_sum();
float cos_max_right_sum();
float cos_max_midpoint_rule();
float cos_max_trapz_rule();

float cos_mean();

/* DOUBLE usage */
double cos_eff_left_sum_d();
double cos_eff_right_sum_d();
double cos_eff_midpoint_rule_d();
double cos_eff_trapz_rule_d();

double cos_max_left_sum_d();
double cos_max_right_sum_d();
double cos_max_midpoint_rule_d();
double cos_max_trapz_rule_d();

double cos_mean_d();

#endif // __COS_FUNC_H__