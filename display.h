#ifndef DISPLAY_H
#define DISPLAY_H
#include "calculation.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void display_read_degree(data_static_t *data_static);
void display_read_values(data_static_t *data_static, data_vector_t *data_vector);
void display_print_matrix(data_static_t *data_static, data_sum_t *data_sum, data_newsistem_t *data_newsistem);
void display_want_to_calculate(data_static_t *data_static, data_vector_t *data_vector);

#endif
