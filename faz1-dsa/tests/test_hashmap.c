/* Hash map testleri.
 * Ust kisim (verilen testler): DEGISTIRME.
 * Alt kisim (KENDI TESTLERIN): 3 testi sen yazacaksin. */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "hashmap.h"
#include "test.h"

static void anahtar(char *buf, size_t n, int i) {
    snprintf(buf, n, "k%d", i);
}

static void test_create_kapasite(void) {
    HashMap *a = hm_create(0);
    HashMap *b = hm_create(16);
    CHECK(a != NULL && b != NULL);
    CHECK(hm_capacity(a) == 8);
    CHECK(hm_capacity(b) == 16);
    CHECK(hm_len(a) == 0);
    hm_free(a);
    hm_free(b);
    hm_free(NULL); /* guvenli olmali */
}

static void test_put_get(void) {
    HashMap *m = hm_create(0);
    CHECK(hm_put(m, "elma", 1));
    CHECK(hm_put(m, "armut", 2));
    int x = 0;
    CHECK(hm_get(m, "elma", &x) && x == 1);
    CHECK(hm_get(m, "armut", &x) && x == 2);
    CHECK(!hm_get(m, "kiraz", &x));
    CHECK(hm_len(m) == 2);
    hm_free(m);
}

static void test_guncelleme(void) {
    HashMap *m = hm_create(0);
    hm_put(m, "a", 1);
    CHECK(hm_put(m, "a", 2));
    int x = 0;
    CHECK(hm_get(m, "a", &x) && x == 2);
    CHECK(hm_len(m) == 1);
    hm_free(m);
}

static void test_remove(void) {
    HashMap *m = hm_create(0);
    hm_put(m, "a", 1);
    hm_put(m, "b", 2);
    CHECK(hm_remove(m, "a"));
    int x = 0;
    CHECK(!hm_get(m, "a", &x));
    CHECK(hm_get(m, "b", &x) && x == 2);
    CHECK(hm_len(m) == 1);
    CHECK(!hm_remove(m, "a"));
    CHECK(!hm_remove(m, "yok"));
    CHECK(hm_len(m) == 1);
    hm_free(m);
}

static void test_anahtar_kopyalanir(void) {
    HashMap *m = hm_create(0);
    char buf[16];
    strcpy(buf, "anahtar");
    hm_put(m, buf, 5);
    strcpy(buf, "xxxxxxx"); /* cagiranin buffer'i degisti */
    int x = 0;
    CHECK(hm_get(m, "anahtar", &x) && x == 5);
    CHECK(!hm_get(m, "xxxxxxx", &x));
    hm_free(m);
}

static void test_buyume_kurali(void) {
    HashMap *m = hm_create(8);
    char k[32];
    for (int i = 0; i < 6; i++) {
        anahtar(k, sizeof k, i);
        hm_put(m, k, i);
    }
    CHECK(hm_capacity(m) == 8);  /* 6*4 = 24 > 8*3 = 24 degil */
    anahtar(k, sizeof k, 6);
    hm_put(m, k, 6);
    CHECK(hm_capacity(m) == 16); /* 7*4 = 28 > 24 -> buyu */
    bool ok = true;
    for (int i = 0; i < 7; i++) {
        int x;
        anahtar(k, sizeof k, i);
        if (!hm_get(m, k, &x) || x != i) ok = false;
    }
    CHECK(ok);
    hm_free(m);
}

static void test_guncelleme_buyutmez(void) {
    HashMap *m = hm_create(8);
    char k[32];
    for (int i = 0; i < 6; i++) {
        anahtar(k, sizeof k, i);
        hm_put(m, k, i);
    }
    for (int j = 0; j < 10; j++) hm_put(m, "k0", 100 + j);
    CHECK(hm_capacity(m) == 8);
    CHECK(hm_len(m) == 6);
    hm_free(m);
}

static void test_karisik_silme(void) {
    HashMap *m = hm_create(0);
    char k[32];
    const int N = 10000;
    for (int i = 0; i < N; i++) {
        anahtar(k, sizeof k, i);
        hm_put(m, k, i);
    }
    for (int i = 0; i < N; i += 2) {
        anahtar(k, sizeof k, i);
        CHECK(hm_remove(m, k));
    }
    CHECK(hm_len(m) == (size_t)(N / 2));
    bool ok = true;
    for (int i = 0; i < N; i++) {
        int x;
        anahtar(k, sizeof k, i);
        bool var = hm_get(m, k, &x);
        if (i % 2 == 0 && var) ok = false;
        if (i % 2 == 1 && (!var || x != i)) ok = false;
    }
    CHECK(ok);
    hm_free(m);
}

static void test_yuz_bin(void) {
    HashMap *m = hm_create(0);
    char k[32];
    const int N = 100000;
    bool ok = true;
    for (int i = 0; i < N; i++) {
        anahtar(k, sizeof k, i);
        if (!hm_put(m, k, i)) ok = false;
    }
    CHECK(ok);
    CHECK(hm_len(m) == (size_t)N);
    CHECK(hm_len(m) * 4 <= hm_capacity(m) * 3);
    ok = true;
    for (int i = 0; i < N; i++) {
        int x;
        anahtar(k, sizeof k, i);
        if (!hm_get(m, k, &x) || x != i) ok = false;
    }
    CHECK(ok);
    hm_free(m);
}

/* ================= KENDI TESTLERIN =================
 * Asagidaki uc testi sen yaz:
 *   1) test_bos_string_anahtar: "" anahtari eklenip okunabilmeli.
 *   2) test_uzun_anahtar: 1000 karakterlik bir anahtar eklenip okunabilmeli.
 *   3) test_hepsini_sil_tekrar_ekle: 1000 anahtar ekle, hepsini sil
 *      (len 0 olmali), sonra hepsini tekrar ekle ve oku.
 * Yazinca main'deki ilgili RUN satirlarinin yorumunu kaldir. */

int main(void) {
    RUN(test_create_kapasite);
    RUN(test_put_get);
    RUN(test_guncelleme);
    RUN(test_remove);
    RUN(test_anahtar_kopyalanir);
    RUN(test_buyume_kurali);
    RUN(test_guncelleme_buyutmez);
    RUN(test_karisik_silme);
    RUN(test_yuz_bin);
    /* RUN(test_bos_string_anahtar); */
    /* RUN(test_uzun_anahtar); */
    /* RUN(test_hepsini_sil_tekrar_ekle); */
    TEST_SUMMARY();
}
