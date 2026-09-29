/* M2 (insertion, merge_rec) ve M9 (gerisi) - Siralama. SPESIFIKASYON: degistirme.
 * Hepsi yerinde (in-place gerekmeyenler gecici bellek ayirabilir) ve ARTAN sirada siralar. */
#ifndef SORT_H
#define SORT_H

#include <stddef.h>

typedef void (*sort_fn)(int *a, size_t n);

void sort_insertion(int *a, size_t n);    /* M2: CLRS 2.1 */
void sort_merge_rec(int *a, size_t n);    /* M2: CLRS 2.3 */

void sort_bubble(int *a, size_t n);       /* M9: hic takas olmayan turda erken cikar */
void sort_selection(int *a, size_t n);
void sort_quick_naive(int *a, size_t n);  /* pivot: ilk ya da son eleman (sirali girdide en kotu durum) */
void sort_quick_rand(int *a, size_t n);   /* rastgele pivot */
void sort_merge_iter(int *a, size_t n);   /* asagidan yukari (iteratif) */
void sort_count(int *a, size_t n);        /* YALNIZCA negatif olmayan degerler */
void sort_radix(int *a, size_t n);        /* YALNIZCA negatif olmayan degerler; LSD */
void sort_shell(int *a, size_t n);

#endif
