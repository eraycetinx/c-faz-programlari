/* M1 - Olcum dizisi (C tazeleme). SPESIFIKASYON: degistirme. */
#ifndef READINGS_H
#define READINGS_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    double *values;  /* heap'teki olcumler; bos yapida NULL olabilir */
    size_t count;    /* olcum sayisi */
    size_t cap;      /* ayrilmis kapasite */
} Readings;

/* Bos yapi: values = NULL, count = 0, cap = 0. */
void readings_init(Readings *r);

/* Sona ekler. Doluysa kapasiteyi 2 katina cikarir (ilk ayirma: 8).
 * Bellek ayrilamazsa false ve yapi degismez. */
bool readings_add(Readings *r, double x);

/* i gecerliyse *out'a yazar ve true; degilse false. */
bool readings_at(const Readings *r, size_t i, double *out);

/* Bossa false. */
bool readings_min(const Readings *r, double *out);
bool readings_max(const Readings *r, double *out);

/* Bellegi birakir, bos duruma dondurur. Iki kez cagirmak guvenli. */
void readings_free(Readings *r);

#endif
