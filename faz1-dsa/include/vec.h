/* Dinamik dizi (vektor) - SPESIFIKASYON. Bu dosyayi degistirme. */
#ifndef VEC_H
#define VEC_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int *data;   /* heap'teki eleman dizisi; bos vektorde NULL olabilir */
    size_t len;  /* eleman sayisi */
    size_t cap;  /* ayrilmis kapasite (eleman cinsinden) */
} Vec;

/* Bos vektor: data = NULL, len = 0, cap = 0. Bellek ayirmak zorunda degil. */
void vec_init(Vec *v);

/* Sona ekler. Kapasite doluysa kapasiteyi BUYUTEREK (ornegin 2 katina)
 * yeniden ayirir; boylece push amortize O(1) olur.
 * Bellek ayrilamazsa false dondurur ve vektor degismez. */
bool vec_push(Vec *v, int x);

/* i gecerliyse *out'a yazar ve true dondurur; degilse false. */
bool vec_get(const Vec *v, size_t i, int *out);

/* i gecerliyse degeri degistirir ve true dondurur; degilse false. */
bool vec_set(Vec *v, size_t i, int x);

/* Son elemani *out'a yazip cikarir (LIFO). Bossa false. */
bool vec_pop(Vec *v, int *out);

/* Bellegi serbest birakir ve vektoru bos duruma dondurur
 * (data = NULL, len = 0, cap = 0). Iki kez cagirmak guvenlidir;
 * sonrasinda vektor yeniden kullanilabilir. */
void vec_free(Vec *v);

#endif
