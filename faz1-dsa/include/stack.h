/* M5 - Yigit: dizi tabanli (StackA) ve bagli liste tabanli (StackL). SPESIFIKASYON: degistirme.
 * Ogeler long: hem sayi hem karakter tasiyabilir. */
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    long *data;
    size_t len;
    size_t cap;
} StackA;

void stacka_init(StackA *s);                     /* bos; bellek ayirmak zorunda degil */
bool stacka_push(StackA *s, long x);             /* doluysa 2 katina buyur */
bool stacka_pop(StackA *s, long *out);           /* bossa false */
bool stacka_peek(const StackA *s, long *out);
bool stacka_empty(const StackA *s);
void stacka_free(StackA *s);                     /* iki kez guvenli */

typedef struct StackNode {
    long value;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
    size_t len;
} StackL;

void stackl_init(StackL *s);
bool stackl_push(StackL *s, long x);
bool stackl_pop(StackL *s, long *out);
bool stackl_peek(const StackL *s, long *out);
bool stackl_empty(const StackL *s);
void stackl_free(StackL *s);

#endif
