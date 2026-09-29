/* String -> int hash map (chaining ile) - SPESIFIKASYON. Bu dosyayi degistirme. */
#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>
#include <stddef.h>

/* Yapinin icerigi src/hashmap.c icinde tanimlanir (opaque tip). */
typedef struct HashMap HashMap;

/* initial_capacity bucket sayisidir. 0 verilirse 8 kullanilir.
 * Bellek ayrilamazsa NULL. */
HashMap *hm_create(size_t initial_capacity);

/* Tum anahtarlari, dugumleri ve bucket dizisini serbest birakir.
 * NULL ile cagrilabilir (hicbir sey yapmaz). */
void hm_free(HashMap *m);

/* Anahtar yoksa ekler, varsa degerini gunceller.
 * Anahtarin KOPYASINI saklar: cagiran taraf kendi buffer'ini sonra
 * degistirebilir.
 * Buyume kurali: YENI bir anahtar eklendikten sonra
 *     len * 4 > capacity * 3   (yani yuk faktoru > 0.75)
 * ise capacity 2 katina cikar ve tum dugumler yeni bucket'lara tasinir.
 * Var olan anahtarin guncellenmesi buyume tetiklemez.
 * Bellek ayrilamazsa false. */
bool hm_put(HashMap *m, const char *key, int value);

/* Anahtar varsa degerini *out'a yazar ve true dondurur; yoksa false. */
bool hm_get(const HashMap *m, const char *key, int *out);

/* Anahtari ve kopyasini siler; bulunamazsa false. Kuculme yok. */
bool hm_remove(HashMap *m, const char *key);

size_t hm_len(const HashMap *m);

/* Bucket sayisi (buyume kuralini test etmek icin). */
size_t hm_capacity(const HashMap *m);

#endif
