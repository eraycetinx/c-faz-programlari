/* M5 - Kuyruklar. SPESIFIKASYON: degistirme.
 * queue.c, Queue2S icin stack.c'yi kullanir: Makefile'da DEPS_queue := src/stack.c */
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>
#include "stack.h"

/* Dairesel dizi, sabit kapasite. Bos yuva harcamadan: head + len ile. */
typedef struct {
    long *data;
    size_t cap;
    size_t head;   /* ilk ogenin indeksi */
    size_t len;
} QueueC;

bool queuec_init(QueueC *q, size_t cap);         /* cap 0 ise false */
bool queuec_enqueue(QueueC *q, long x);          /* doluysa false */
bool queuec_dequeue(QueueC *q, long *out);       /* bossa false */
bool queuec_empty(const QueueC *q);
bool queuec_full(const QueueC *q);
void queuec_free(QueueC *q);

/* Bagli liste tabanli kuyruk. */
typedef struct QNode {
    long value;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
    size_t len;
} QueueL;

void queuel_init(QueueL *q);
bool queuel_enqueue(QueueL *q, long x);
bool queuel_dequeue(QueueL *q, long *out);
bool queuel_empty(const QueueL *q);
void queuel_free(QueueL *q);

/* Iki uclu kuyruk: dairesel dizi, sabit kapasite. */
typedef struct {
    long *data;
    size_t cap;
    size_t head;
    size_t len;
} Deque;

bool deque_init(Deque *d, size_t cap);
bool deque_push_front(Deque *d, long x);
bool deque_push_back(Deque *d, long x);
bool deque_pop_front(Deque *d, long *out);
bool deque_pop_back(Deque *d, long *out);
void deque_free(Deque *d);

/* Iki yigitla kuyruk: dequeue amortize O(1). */
typedef struct {
    StackA in;
    StackA out;
} Queue2S;

void queue2s_init(Queue2S *q);
bool queue2s_enqueue(Queue2S *q, long x);
bool queue2s_dequeue(Queue2S *q, long *out);
void queue2s_free(Queue2S *q);

#endif
