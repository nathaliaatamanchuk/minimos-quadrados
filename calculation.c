#include "calculation.h"

void sum(data_static_t *data_static, data_vector_t *data_vector, data_sum_t *data_sum) {
    data_sum->sumX = 0;
    data_sum->sumY = 0;
    data_sum->sumXSquared = 0;
    data_sum->sumXCubed = 0;
    data_sum->sumXQuad = 0;
    data_sum->sumYtimesX = 0;
    data_sum->sumYtimesXSquared = 0;

    for (int i = 0; i <data_static->point; i++, data_vector++) {
        data_sum->sumY += data_vector->y;
        data_sum->sumYtimesX += data_vector->y * data_vector->x;
        data_sum->sumYtimesXSquared += data_vector->y * pow(data_vector->x, 2);

        data_sum->sumX += data_vector->x;
        data_sum->sumXSquared += pow(data_vector->x, 2);
        data_sum->sumXCubed += pow(data_vector->x, 3);
        data_sum->sumXQuad += pow(data_vector->x, 4);
    }
}

void line_times(data_static_t *data_static, data_sum_t *data_sum, data_gauss_t *data_gauss, data_newsistem_t *data_newsistem){
    double a, b, c, d;

    if (!data_static || !data_sum || !data_gauss) {
        // Erro: um ou mais ponteiros são nulos
        return;
    }

    if(data_static->degree == 1 && data_static->point != 0) {
        float point_inv = 1.0f / data_static->point;
        data_gauss->lineMultiplierSec = data_sum->sumX * point_inv;

        data_newsistem->row1_col1 = data_static->point;
        data_newsistem->row1_col2 = data_sum->sumX;
        data_newsistem->row1_col3 = data_sum->sumY;

        data_newsistem->row2_col1 = data_sum->sumX - data_gauss->lineMultiplierSec * data_static->point;
        data_newsistem->row2_col2 = data_sum->sumXSquared - data_gauss->lineMultiplierSec * data_sum->sumX;
        data_newsistem->row2_col3 = data_sum->sumYtimesX - data_gauss->lineMultiplierSec * data_sum->sumY;
    }

    if(data_static->degree == 2 && data_static->point != 0) {
        float point_inv = 1.0f / data_static->point;

        data_gauss->lineMultiplierSec = data_sum->sumX * point_inv;
        data_gauss->lineMultiplierThird = data_sum->sumXSquared * point_inv;

        data_newsistem->row1_col1 = data_static->point;
        data_newsistem->row1_col2 = data_sum->sumX;
        data_newsistem->row1_col3 = data_sum->sumXSquared;
        data_newsistem->row1_col4 = data_sum->sumY;

        data_newsistem->row2_col1 = data_sum->sumX - data_gauss->lineMultiplierSec * data_static->point;
        data_newsistem->row2_col2 = data_sum->sumXSquared - data_gauss->lineMultiplierSec * data_sum->sumX;
        data_newsistem->row2_col3 = data_sum->sumXCubed - data_gauss->lineMultiplierSec * data_sum->sumXSquared;
        data_newsistem->row2_col4 = data_sum->sumYtimesX - data_gauss->lineMultiplierSec * data_sum->sumY;

        a = data_sum->sumXSquared - data_gauss->lineMultiplierThird * data_static->point;
        b = data_sum->sumXCubed - data_gauss->lineMultiplierThird * data_sum->sumX;
        c = data_sum->sumXQuad - data_gauss->lineMultiplierThird * data_sum->sumXSquared;
        d = data_sum->sumYtimesXSquared  - data_gauss->lineMultiplierThird * data_sum->sumY;

        data_gauss->lineMultiplierThirdTwo = b / data_newsistem->row2_col2;

        data_newsistem->row3_col1 = a - data_gauss->lineMultiplierThirdTwo * data_newsistem->row2_col1;
        data_newsistem->row3_col2 = b - data_gauss->lineMultiplierThirdTwo * data_newsistem->row2_col2;
        data_newsistem->row3_col3 = c - data_gauss->lineMultiplierThirdTwo * data_newsistem->row2_col3;
        data_newsistem->row3_col4 = d - data_gauss->lineMultiplierThirdTwo * data_newsistem->row2_col4;
    }
}

void polynomial(data_static_t *data_static, data_newsistem_t *data_newsistem) {
    if(data_static->degree == 1) {
        data_newsistem->a1 = (data_newsistem->row2_col3 / data_newsistem->row2_col2);
        data_newsistem->a0 = ((data_newsistem->row1_col3 - (data_newsistem->row1_col2 * data_newsistem->a1)) / data_newsistem->row1_col1);
    }
    if(data_static->degree == 2) {
        data_newsistem->a2 = (data_newsistem->row3_col4 / data_newsistem->row3_col3);
        data_newsistem->a1 = ((data_newsistem->row2_col4 - (data_newsistem->row2_col3 * data_newsistem->a2)) / data_newsistem->row2_col2);
        data_newsistem->a0 = ((data_newsistem->row1_col4 - (data_newsistem->row1_col3 * data_newsistem->a2) - (data_newsistem->row1_col2 * data_newsistem->a1)) / data_newsistem->row1_col1);
    }
}


