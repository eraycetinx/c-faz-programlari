/* M8 - Min-oncelik kuyrugu (ikili heap). SPESIFIKASYON: degistirme.
 * Ogeler 0..capacity-1 arasindaki id'lerle tanimlanir. decrease_key icin
 * id -> heap konumu esleme dizisi tutulur. Dijkstra ve Prim bunu kullanir. */
#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include <stddef.h>

typedef struct PQ PQ;

PQ *pq_create(size_t capacity);                      /* bellek yoksa NULL */
void pq_free(PQ *q);                                 /* NULL ile cagrilabilir */
bool pq_push(PQ *q, size_t id, long key);            /* id aralik disi ya da zaten icerideyse false */
bool pq_pop_min(PQ *q, size_t *id, long *key);       /* bossa false */
bool pq_peek_min(const PQ *q, size_t *id, long *key);
bool pq_decrease_key(PQ *q, size_t id, long new_key);/* id iceride degilse ya da new_key buyukse false */
bool pq_contains(const PQ *q, size_t id);
size_t pq_size(const PQ *q);

#endif
