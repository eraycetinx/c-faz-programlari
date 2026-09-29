/* M4 - Tek yonlu bagli liste (bas isaretcisiyle). SPESIFIKASYON: degistirme.
 * Konumlar 0'dan baslar. Abdul Bari insert/delete'te 1'den baslayan konum kullanir;
 * burada 0 = ilk dugum. */
#ifndef SLIST_H
#define SLIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct SNode {
    int value;
    struct SNode *next;
} SNode;

/* Diziden liste kurar (sona ekleyerek). n == 0 ise NULL.
 * Bellek biterse o ana kadar ayrilani birakir ve NULL dondurur. */
SNode *slist_from_array(const int *a, size_t n);
void slist_free(SNode **head);                              /* *head = NULL */

/* Dugum sayisini dondurur; en fazla cap degeri out'a yazar. */
size_t slist_to_array(const SNode *head, int *out, size_t cap);

size_t slist_count(const SNode *head);
size_t slist_count_rec(const SNode *head);
long long slist_sum(const SNode *head);
bool slist_max(const SNode *head, int *out);                /* bossa false */

SNode *slist_search(SNode *head, int key);                  /* yoksa NULL */
SNode *slist_search_mtf(SNode **head, int key);             /* bulursa dugumu basa tasir */

bool slist_insert(SNode **head, size_t pos, int x);         /* 0 <= pos <= count */
bool slist_insert_sorted(SNode **head, int x);              /* sirali listeye */
bool slist_delete(SNode **head, size_t pos, int *out);      /* 0 <= pos < count */

bool slist_is_sorted(const SNode *head);                    /* bos ve tek dugum: true */
void slist_remove_dups_sorted(SNode *head);                 /* sirali listede ardisik tekrarlari sil */

void slist_reverse(SNode **head);                           /* kayan isaretciler, O(1) ek bellek */
void slist_reverse_rec(SNode **head);

void slist_concat(SNode **a, SNode *b);                     /* b'nin dugumleri a'nin sonuna baglanir */
SNode *slist_merge_sorted(SNode *a, SNode *b);              /* yeni dugum ayirmadan birlestirir */

bool slist_has_loop(const SNode *head);                     /* Floyd: yavas/hizli isaretci */
/* Tek gecis. n dugumde 0 tabanli n/2. dugum (cift n'de ikinci ortanca). Bossa false. */
bool slist_middle(const SNode *head, int *out);
/* Iki listenin paylastigi ilk dugum (ayni adres); yoksa NULL. */
SNode *slist_intersection(SNode *a, SNode *b);

#endif
