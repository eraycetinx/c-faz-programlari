/* M4 - Cift yonlu bagli liste. SPESIFIKASYON: degistirme. */
#ifndef DLIST_H
#define DLIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct DNode {
    int value;
    struct DNode *prev;
    struct DNode *next;
} DNode;

DNode *dlist_from_array(const int *a, size_t n);
void dlist_free(DNode **head);
size_t dlist_to_array(const DNode *head, int *out, size_t cap);
/* Sondan basa, prev baglarini izleyerek yazar: prev baglarini dogrulamak icin. */
size_t dlist_to_array_rev(const DNode *head, int *out, size_t cap);
bool dlist_insert(DNode **head, size_t pos, int x);      /* 0 <= pos <= count */
bool dlist_delete(DNode **head, size_t pos, int *out);   /* 0 <= pos < count */
void dlist_reverse(DNode **head);

#endif
