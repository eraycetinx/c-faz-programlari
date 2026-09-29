/* Vektor testleri. Bu dosyayi degistirme; sadece oku. */
#include <stdbool.h>
#include "vec.h"
#include "test.h"

static void test_init_bos(void) {
    Vec v;
    vec_init(&v);
    int x;
    CHECK(v.len == 0);
    CHECK(!vec_get(&v, 0, &x));
    CHECK(!vec_pop(&v, &x));
    vec_free(&v);
}

static void test_push_get(void) {
    Vec v;
    vec_init(&v);
    for (int i = 0; i < 10; i++) CHECK(vec_push(&v, i * i));
    CHECK(v.len == 10);
    bool ok = true;
    for (size_t i = 0; i < 10; i++) {
        int x = -1;
        if (!vec_get(&v, i, &x) || x != (int)(i * i)) ok = false;
    }
    CHECK(ok);
    int x;
    CHECK(!vec_get(&v, 10, &x));
    vec_free(&v);
}

static void test_set(void) {
    Vec v;
    vec_init(&v);
    for (int i = 0; i < 5; i++) vec_push(&v, i);
    CHECK(vec_set(&v, 3, 42));
    int x = 0;
    CHECK(vec_get(&v, 3, &x) && x == 42);
    CHECK(!vec_set(&v, 5, 1));
    CHECK(v.len == 5);
    vec_free(&v);
}

static void test_pop_lifo(void) {
    Vec v;
    vec_init(&v);
    vec_push(&v, 1);
    vec_push(&v, 2);
    vec_push(&v, 3);
    int x = 0;
    CHECK(vec_pop(&v, &x) && x == 3);
    CHECK(vec_pop(&v, &x) && x == 2);
    CHECK(vec_pop(&v, &x) && x == 1);
    CHECK(!vec_pop(&v, &x));
    CHECK(v.len == 0);
    vec_free(&v);
}

static void test_bir_milyon(void) {
    Vec v;
    vec_init(&v);
    const int N = 1000000;
    bool ok = true;
    for (int i = 0; i < N; i++)
        if (!vec_push(&v, i)) ok = false;
    CHECK(ok);
    CHECK(v.len == (size_t)N);
    CHECK(v.cap >= v.len);
    CHECK(v.cap <= 4 * v.len); /* kapasite gereksiz buyuk olmamali */
    ok = true;
    for (int i = 0; i < N; i++) {
        int x;
        if (!vec_get(&v, (size_t)i, &x) || x != i) ok = false;
    }
    CHECK(ok);
    vec_free(&v);
}

static void test_free_ve_yeniden_kullanim(void) {
    Vec v;
    vec_init(&v);
    for (int i = 0; i < 100; i++) vec_push(&v, i);
    vec_free(&v);
    CHECK(v.data == NULL && v.len == 0 && v.cap == 0);
    vec_free(&v); /* ikinci free guvenli olmali */
    CHECK(vec_push(&v, 7));
    int x = 0;
    CHECK(vec_get(&v, 0, &x) && x == 7);
    vec_free(&v);
}

int main(void) {
    RUN(test_init_bos);
    RUN(test_push_get);
    RUN(test_set);
    RUN(test_pop_lifo);
    RUN(test_bir_milyon);
    RUN(test_free_ve_yeniden_kullanim);
    TEST_SUMMARY();
}
