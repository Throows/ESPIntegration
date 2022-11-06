#ifndef __INTEGRATE_FUNC_H__
#define __INTEGRATE_FUNC_H__
#include "Data.h"

/* FLOAT usage */
float eff_left_sum();
float eff_right_sum();
float eff_midpoint_rule();
float eff_trapz_rule();

float mean_left_sum();
float mean_right_sum();
float mean_midpoint_rule();
float mean_trapz_rule();

float mean();

/* DOUBLE usage */
double eff_left_sum_d();
double eff_right_sum_d();
double eff_midpoint_rule_d();
double eff_trapz_rule_d();

double mean_left_sum_d();
double mean_right_sum_d();
double mean_midpoint_rule_d();
double mean_trapz_rule_d();

double mean_d();

#endif // __INTEGRATE_FUNC_H__