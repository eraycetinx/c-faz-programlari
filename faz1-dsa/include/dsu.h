/* M11 - Ayrik kumeler (union-find). SPESIFIKASYON: degistirme. */
#ifndef DSU_H
#define DSU_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DSU DSU;

DSU *dsu_create(size_t n);                  /* 0..n-1, her eleman kendi kumesinde */
void dsu_free(DSU *d);                      /* NULL ile cagrilabilir */
size_t dsu_find(DSU *d, size_t x);          /* yol sikistirmali */
bool dsu_union(DSU *d, size_t a, size_t b); /* rank ile birlesim; zaten ayni kumedeyse false */
size_t dsu_sets(const DSU *d);              /* guncel kume sayisi */

#endif
