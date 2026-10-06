#include "test.h"
#include "../include/readings.h"

/*
 * Bos yapida min ve max false donmeli.
 */
static void test_empty_min_max(void)
{
    Readings r = {0};

    double out = 0.0;

    CHECK(readings_min(&r, &out) == false);
    CHECK(readings_max(&r, &out) == false);

    readings_free(&r);
}

/*
 * Uc ekleme sonrasi at dogru degerleri vermeli.
 * Sinir disi index false donmeli.
 */
static void test_at(void)
{
    Readings r = {0};

    CHECK(readings_add(&r, 10.0));
    CHECK(readings_add(&r, 20.0));
    CHECK(readings_add(&r, 30.0));

    double out = 0.0;

    CHECK(readings_at(&r, 0, &out));
    CHECK(out == 10.0);

    CHECK(readings_at(&r, 1, &out));
    CHECK(out == 20.0);

    CHECK(readings_at(&r, 2, &out));
    CHECK(out == 30.0);

    /* count = 3, dolayisiyla index 3 sinir disidir. */
    CHECK(readings_at(&r, 3, &out) == false);

    readings_free(&r);
}

/*
 * Negatif degerlerle min ve max dogru calismali.
 */
static void test_negative_min_max(void)
{
    Readings r = {0};

    CHECK(readings_add(&r, -10.0));
    CHECK(readings_add(&r, -50.0));
    CHECK(readings_add(&r, -3.0));
    CHECK(readings_add(&r, -25.0));

    double min = 0.0;
    double max = 0.0;

    CHECK(readings_min(&r, &min));
    CHECK(readings_max(&r, &max));

    CHECK(min == -50.0);
    CHECK(max == -3.0);

    readings_free(&r);
}

/*
 * 100000 ekleme sorunsuz yapilmali.
 */
static void test_100000_adds(void)
{
    Readings r = {0};

    for (size_t i = 0; i < 100000; i++)
    {
        CHECK(readings_add(&r, (double)i));
    }

    CHECK(r.count == 100000);

    double out = 0.0;

    /* Ilk degeri kontrol et. */
    CHECK(readings_at(&r, 0, &out));
    CHECK(out == 0.0);

    /* Ortalardan bir degeri kontrol et. */
    CHECK(readings_at(&r, 50000, &out));
    CHECK(out == 50000.0);

    /* Son elemani kontrol et. */
    CHECK(readings_at(&r, 99999, &out));
    CHECK(out == 99999.0);

    readings_free(&r);
}

/*
 * free sonrasi yapi bos olmali.
 * Ikinci free guvenli olmali.
 * Sonrasinda yapi tekrar kullanilabilmeli.
 */
static void test_free_and_reuse(void)
{
    Readings r = {0};

    CHECK(readings_add(&r, 42.0));
    CHECK(readings_add(&r, 84.0));

    readings_free(&r);

    /* Bos duruma dondu mu? */
    CHECK(r.values == NULL);
    CHECK(r.count == 0);
    CHECK(r.cap == 0);

    /* Ikinci kez free: program cokmemeli. */
    readings_free(&r);

    CHECK(r.values == NULL);
    CHECK(r.count == 0);
    CHECK(r.cap == 0);

    /* Ayni yapi yeniden kullanilabilmeli. */
    CHECK(readings_add(&r, 123.0));

    CHECK(r.count == 1);
    CHECK(r.cap == 8);

    double out = 0.0;

    CHECK(readings_at(&r, 0, &out));
    CHECK(out == 123.0);

    readings_free(&r);
}

int main(void)
{
    RUN(test_empty_min_max);
    RUN(test_at);
    RUN(test_negative_min_max);
    RUN(test_100000_adds);
    RUN(test_free_and_reuse);

    TEST_SUMMARY();
}