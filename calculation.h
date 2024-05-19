#ifndef CALCULATION_H
#define CALCULATION_H
#include <math.h>
#include <stdio.h>

typedef struct {
    int degree;
    int point;
    double *coefficient;
}data_static_t;

typedef struct {
    double x;
    double y;
}data_vector_t;

typedef struct {
    double sumX;
    double sumY;
    double sumXSquared;
    double sumXCubed;
    double sumXQuad;
    double sumYtimesX;
    double sumYtimesXSquared;
}data_sum_t;

typedef struct {
    double pivot;
    int k;
    int i;
    double lineMultiplierSec;
    double lineMultiplierThird;
    double lineMultiplierThirdTwo;
}data_gauss_t;

typedef struct {
    double row1_col1;
    double row1_col2;
    double row1_col3;
    double row1_col4;
    double row2_col1;
    double row2_col2;
    double row2_col3;
    double row2_col4;
    double row3_col1;
    double row3_col2;
    double row3_col3;
    double row3_col4;
    double a0;
    double a1;
    double a2;
}data_newsistem_t;

void sum(data_static_t *data_static, data_vector_t *data_vector, data_sum_t *data_sum);
void multipliers(data_static_t *data_static, data_sum_t *data_sum, data_gauss_t *data_gauss);
void line_times(data_static_t *data_static, data_sum_t *data_sum, data_gauss_t *data_gauss, data_newsistem_t *data_newsistem);
void polynomial(data_static_t *data_static, data_newsistem_t *data_newsistem);

#endif
