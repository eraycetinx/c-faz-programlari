/* M10 - String -> int hash map, open addressing (linear probing). SPESIFIKASYON: degistirme.
 * API hashmap.h ile ayni mantikta; onek hmo_. */
#ifndef HASHMAP_OA_H
#define HASHMAP_OA_H

#include <stdbool.h>
#include <stddef.h>

typedef struct HashMapOA HashMapOA;

HashMapOA *hmo_create(size_t initial_capacity);   /* 0 ise 8 */
void hmo_free(HashMapOA *m);                      /* NULL ile cagrilabilir */

/* Anahtar yoksa ekler, varsa gunceller; anahtarin kopyasini saklar.
 * Silinen yuvalar tombstone olarak isaretlenir.
 * Buyume kurali: YENI anahtar eklendikten sonra
 *     (len + tombstones) * 2 > capacity
 * ise capacity 2 katina cikar, canli anahtarlar yeniden yerlestirilir,
 * tombstone'lar temizlenir. Guncelleme buyume tetiklemez. */
bool hmo_put(HashMapOA *m, const char *key, int value);
bool hmo_get(const HashMapOA *m, const char *key, int *out);
bool hmo_remove(HashMapOA *m, const char *key);
size_t hmo_len(const HashMapOA *m);
size_t hmo_capacity(const HashMapOA *m);

/* Olcum icin: key'i bulmak (ya da olmadigini anlamak) icin yoklanan yuva sayisi. */
size_t hmo_probe_count(const HashMapOA *m, const char *key);

#endif
