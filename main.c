#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "calculation.h"
#include "display.h"
#include "allocation.h"

int main(void)
{
    data_static_t data_static;
    data_sum_t data_sum;
    data_gauss_t data_gauss;
    data_newsistem_t data_newsistem;
    data_vector_t *data_vector = NULL;
    char answer;

    do {

        display_read_degree(&data_static);
        aloca_struct(&data_vector, data_static.point);
        display_read_values(&data_static, data_vector);
        sum(&data_static, data_vector, &data_sum);
        line_times(&data_static, &data_sum, &data_gauss, &data_newsistem);
        polynomial(&data_static, &data_newsistem);
        display_print_matrix(&data_static, &data_sum, &data_newsistem);
        printf("\nDeseja calcular outro valor (S/N)? ");
        scanf(" %c", &answer);
        system("cls");
    }while (tolower(answer) == 's');

    return 0;
}
