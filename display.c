#include "display.h"

void display_read_degree(data_static_t *data_static)
{
    printf("Digite o grau da funcao: ");
    scanf(" %d", &data_static->degree);
    printf("Digite o numero de pontos existentes da funcao");
    scanf(" %d", &data_static->point);
}

void display_read_values(data_static_t *data_static, data_vector_t *data_vector){
    int i;
    printf("Digite os valores de x e de f(x):\n");

    for (i = 0; i < data_static->point; i++, data_vector++) {
        printf("x[%d] = ", i);
        scanf(" %lf", &data_vector->x);
        printf("f(x[%d]) = ", i);
        scanf(" %lf", &data_vector->y);
    }
}

void display_print_matrix(data_static_t *data_static, data_sum_t *data_sum, data_newsistem_t *data_newsistem){
    if(data_static->degree == 1) {

        printf("\n\nMatriz do sistema:\n");
        printf("|%02d\t%02.3lf\t|   |A0|   |%02.3lf|\n", data_static->point, data_sum->sumX, data_sum->sumY);
        printf("|%02.3lf\t%02.3lf\t| x |A1| = |%02.3lf|\n", data_sum->sumX, data_sum->sumXSquared, data_sum->sumYtimesX);

        printf("\nMatriz aumentada do sistema (A|B):\n");
        printf("|%02d\t%02.3lf\t |\t%.3lf|\n", data_static->point, data_sum->sumX, data_sum->sumY);
        printf("|%02.3lf\t%02.3lf\t |\t%.3lf|\n", data_sum->sumX, data_sum->sumXSquared, data_sum->sumYtimesX);

        printf("\nSistema:\n");
        printf("%02da^0 + %02.3lfa^1 = %02.3lf\n", data_static->point, data_sum->sumX, data_sum->sumY);
        printf("%02.3lfa^0 + %02.3lfa^1 = %02.3lf\n", data_sum->sumX, data_sum->sumXSquared, data_sum->sumYtimesX);

        printf("\n==========================================\n");

        printf("\nMatriz Final:\n");
        printf("|%02.3lf\t%02.3lf\t |\t%.3lf|\n", data_newsistem->row1_col1, data_newsistem->row1_col2, data_newsistem->row1_col4);
        printf("|%02.3lf\t%02.3lf\t |\t%.3lf|\n", data_newsistem->row2_col1, data_newsistem->row2_col2, data_newsistem->row2_col4);

        printf("\nSistema Final:\n");
        printf("%02.3lfa^0 + %02.3lfa^1 = %02.3lf\n", data_newsistem->row1_col1, data_newsistem->row1_col2, data_newsistem->row1_col4);
        printf("%02.3lfa^0 + %02.3lfa^1 = %02.3lf\n", data_newsistem->row2_col1, data_newsistem->row2_col2, data_newsistem->row2_col4);

        printf("\nPolinomio final:\n");
        printf("P(x) = %02.3lf + %02.3lfx\n", data_newsistem->a0, data_newsistem->a1);
    }

    else if(data_static->degree == 2) {
        printf("\n\nMatriz do sistema:\n");
        printf("|%02d\t%02.3lf\t%02.3lf|   |A0|   |%02.3lf|\n", data_static->point, data_sum->sumX, data_sum->sumXSquared, data_sum->sumY);
        printf("|%02.3lf\t%02.3lf\t%02.3lf| x |A1| = |%02.3lf|\n", data_sum->sumX, data_sum->sumXSquared, data_sum->sumXCubed, data_sum->sumYtimesX);
        printf("|%02.3lf\t%02.3lf\t%02.3lf|   |A2|   |%02.3lf|\n", data_sum->sumXSquared, data_sum->sumXCubed, data_sum->sumXQuad, data_sum->sumYtimesXSquared);

        printf("\nMatriz aumentada do sistema (A|B):\n");
        printf("|%02d\t%02.3lf\t%02.3lf |\t%.3lf|\n", data_static->point, data_sum->sumX, data_sum->sumXSquared, data_sum->sumY);
        printf("|%02.3lf\t%02.3lf\t%02.3lf |\t%.3lf|\n", data_sum->sumX, data_sum->sumXSquared, data_sum->sumXCubed, data_sum->sumYtimesX);
        printf("|%02.3lf\t%02.3lf\t%02.3lf |\t%.3lf|\n", data_sum->sumXSquared, data_sum->sumXCubed, data_sum->sumXQuad, data_sum->sumYtimesXSquared);

        printf("\nSistema:\n");
        printf("%02da^0 + %02.3lfa^1 + %02.3lfa^2 = %02.3lf\n", data_static->point, data_sum->sumX, data_sum->sumXSquared, data_sum->sumY);
        printf("%02.3lfa^0 + %02.3lfa^1 + %02.3lfa^2 = %02.3lf\n", data_sum->sumX, data_sum->sumXSquared, data_sum->sumXCubed, data_sum->sumYtimesX);
        printf("%02.3lfa^0 + %02.3lfa^1 + %02.3lfa^2 = %02.3lf\n", data_sum->sumXSquared, data_sum->sumXCubed, data_sum->sumXQuad, data_sum->sumYtimesXSquared);

        printf("\n==========================================\n");

        printf("\nMatriz Final:\n");
        printf("|%02.3lf\t%02.3lf\t%02.3lf |\t%.3lf|\n", data_newsistem->row1_col1, data_newsistem->row1_col2, data_newsistem->row1_col3, data_newsistem->row1_col4);
        printf("|%02.3lf\t%02.3lf\t%02.3lf |\t%.3lf|\n", data_newsistem->row2_col1, data_newsistem->row2_col2, data_newsistem->row2_col3, data_newsistem->row2_col4);
        printf("|%02.3lf\t%02.3lf\t%02.3lf |\t%.3lf|\n", data_newsistem->row3_col1, data_newsistem->row3_col2, data_newsistem->row3_col3, data_newsistem->row3_col4);

        printf("\nSistema Final:\n");
        printf("%02.3lfa^0 + %02.3lfa^1 + %02.3lfa^2 = %02.3lf\n", data_newsistem->row1_col1, data_newsistem->row1_col2, data_newsistem->row1_col3, data_newsistem->row1_col4);
        printf("%02.3lfa^0 + %02.3lfa^1 + %02.3lfa^2 = %02.3lf\n", data_newsistem->row2_col1, data_newsistem->row2_col2, data_newsistem->row2_col3, data_newsistem->row2_col4);
        printf("%02.3lfa^0 + %02.3lfa^1 + %02.3lfa^2 = %02.3lf\n", data_newsistem->row3_col1, data_newsistem->row3_col2, data_newsistem->row3_col3, data_newsistem->row3_col4);

        printf("\nPolinomio final:\n");
        printf("P(x) = %02.3lf + %02.3lfx + %02.3lfx^2\n", data_newsistem->a0, data_newsistem->a1, data_newsistem->a2);
    }
}



