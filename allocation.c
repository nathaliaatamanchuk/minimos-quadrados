#include "allocation.h"

void aloca_struct(data_vector_t **data_vector, int point) {
    *data_vector = (data_vector_t *)malloc(point * sizeof(data_vector_t));
    if(*data_vector == NULL) {
        printf("ERROR!\n");
        exit(1);
    }
}

// void aloca_coefficient(data_static_t *data_static, int point) {
//     data_static->coefficient = (double *)malloc((data_static->degree + 1) * sizeof(double));
//     if (data_static->coefficient == NULL) {
//         printf("ERROR!\n");
//         exit(1);
//     }
// }


