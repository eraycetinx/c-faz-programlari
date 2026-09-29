/* Minik test yardimcisi. Degistirme. */
#ifndef TEST_H
#define TEST_H

#include <stdio.h>

static int test_failures = 0;
static int test_checks = 0;

/* Kosul yanlissa dosya:satir ile raporlar, testi durdurmaz. */
#define CHECK(cond) do {                                              \
        test_checks++;                                                \
        if (!(cond)) {                                                \
            test_failures++;                                          \
            fprintf(stderr, "  HATA %s:%d: %s\n",                     \
                    __FILE__, __LINE__, #cond);                       \
        }                                                             \
    } while (0)

/* Bir test fonksiyonunu calistirir ve OK/FAIL yazar. */
#define RUN(fn) do {                                                  \
        int before_ = test_failures;                                  \
        fn();                                                         \
        printf("%s %s\n",                                             \
               test_failures == before_ ? "[ OK ]" : "[FAIL]", #fn);  \
    } while (0)

/* main'in son satiri olarak kullan. Hata varsa cikis kodu 1 olur. */
#define TEST_SUMMARY() do {                                           \
        printf("%d kontrol, %d hata\n", test_checks, test_failures);  \
        return test_failures == 0 ? 0 : 1;                            \
    } while (0)

#endif
