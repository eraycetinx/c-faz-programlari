/* M3 - Array ADT. SPESIFIKASYON: degistirme.
 * Konumlar 0'dan baslar (Abdul Bari'nin anlatimiyla ayni). */
#ifndef ARR_H
#define ARR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int *a;
    size_t len;
    size_t cap;
} Array;

bool arr_init(Array *x, size_t cap);            /* cap 0 ise 8; len = 0 */
void arr_free(Array *x);                        /* a = NULL, len = cap = 0; iki kez guvenli */

bool arr_append(Array *x, int v);               /* doluysa kapasite 2 katina */
bool arr_insert(Array *x, size_t i, int v);     /* 0 <= i <= len; elemanlari kaydirarak */
bool arr_delete(Array *x, size_t i, int *out);  /* 0 <= i < len */
bool arr_get(const Array *x, size_t i, int *out);
bool arr_set(Array *x, size_t i, int v);

bool arr_linear_search(const Array *x, int key, size_t *idx);
bool arr_binary_search(const Array *x, int key, size_t *idx);      /* sirali dizi; iteratif */
bool arr_binary_search_rec(const Array *x, int key, size_t *idx);  /* sirali dizi; ozyinelemeli */

bool arr_max(const Array *x, int *out);         /* bossa false */
bool arr_min(const Array *x, int *out);
long long arr_sum(const Array *x);
bool arr_avg(const Array *x, double *out);      /* bossa false */

void arr_reverse(Array *x);                     /* yerinde */
void arr_rotate_left(Array *x, size_t k);       /* k, len'den buyuk olabilir */
bool arr_is_sorted(const Array *x);             /* a[i] <= a[i+1]; bos ve tek eleman: true */
bool arr_insert_sorted(Array *x, int v);        /* sirali diziye, sirayi bozmadan */
void arr_negatives_first(Array *x);             /* negatifler basa; sira korunmak zorunda degil */

/* Asagidakiler out'u KENDISI init eder; cagiran sonra arr_free(out) yapar.
 * arr_merge: a ve b sirali; tekrarlar korunur.
 * Kume islemleri: a ve b sirali ve kendi iclerinde tekrarsiz. */
bool arr_merge(const Array *a, const Array *b, Array *out);
bool arr_union(const Array *a, const Array *b, Array *out);
bool arr_intersection(const Array *a, const Array *b, Array *out);
bool arr_difference(const Array *a, const Array *b, Array *out);   /* a - b */

/* Student Challenge'lar */
/* Sirali dizide min..max araligindaki eksik degerleri artan sirada out'a yazar
 * (en fazla cap). Toplam eksik sayisini dondurur. */
size_t arr_missing_sorted(const Array *x, int *out, size_t cap);
/* Sirasiz dizide birden fazla gecen her degeri BIR kez, artan sirada yazar.
 * Degerler 0..100000 araliginda varsayilir (sayac dizisi yontemi). */
size_t arr_duplicates(const Array *x, int *out, size_t cap);
/* Sirasiz dizide a[i] + a[j] == k ve i < j olan bir cift bulur.
 * Degerler 0..100000 araliginda varsayilir. */
bool arr_pair_sum(const Array *x, int k, size_t *i, size_t *j);
/* Sirali dizide iki isaretciyle ayni is. */
bool arr_pair_sum_sorted(const Array *x, int k, size_t *i, size_t *j);
/* Tek taramada en kucuk ve en buyuk. Bossa false. */
bool arr_minmax(const Array *x, int *mn, int *mx);

#endif
