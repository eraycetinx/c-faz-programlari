/* TATBIKAT 5: segmentation fault. gdb ile nerede oldugunu bul. */
#include <stdio.h>
#include <stddef.h>

typedef struct Kutu {
    int deger;
    struct Kutu *sonraki;
} Kutu;

static int topla(const Kutu *k, int adim) {
    int t = 0;
    for (int i = 0; i < adim; i++) {
        t += k->deger;   /* k NULL olunca burada coker */
        k = k->sonraki;
    }
    return t;
}

int main(void) {
    Kutu c = {3, NULL};
    Kutu b = {2, &c};
    Kutu a = {1, &b};
    printf("%d\n", topla(&a, 3)); /* dogru: 6 */
    printf("%d\n", topla(&a, 4)); /* hatali: 4 adim, 3 kutu var */
    return 0;
}
