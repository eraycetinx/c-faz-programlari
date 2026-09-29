/* M3 - Row-major tek blok matris. SPESIFIKASYON: degistirme. */
#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    double *data;   /* rows * cols eleman, tek malloc */
    size_t rows;
    size_t cols;
} Matrix;

/* Tek blok ayirir ve sifirlar. rows ya da cols 0 ise false. */
bool mat_init(Matrix *m, size_t rows, size_t cols);
void mat_free(Matrix *m);   /* data = NULL, rows = cols = 0; iki kez guvenli */

/* Row-major: &data[r * cols + c]. Sinir disindaysa NULL. */
double *mat_at(Matrix *m, size_t r, size_t c);

#endif
