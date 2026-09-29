/* M4 - Dairesel tek yonlu bagli liste. SPESIFIKASYON: degistirme.
 * head ilk dugumu gosterir; son dugumun next'i head'dir. Bos liste: NULL. */
#ifndef CLIST_H
#define CLIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct CNode {
    int value;
    struct CNode *next;
} CNode;

bool clist_insert(CNode **head, size_t pos, int x);     /* 0 <= pos <= count; pos 0 yeni bas olur */
bool clist_delete(CNode **head, size_t pos, int *out);  /* 0 <= pos < count */
size_t clist_count(const CNode *head);
size_t clist_to_array(const CNode *head, int *out, size_t cap);  /* head'den baslayarak bir tur */
void clist_free(CNode **head);                          /* *head = NULL */

#endif
