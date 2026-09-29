/* TATBIKAT 2: heap tasmasi (sinirin bir otesine yazma). */
#include <stdlib.h>

int main(void) {
    int *a = malloc(10 * sizeof *a);
    for (int i = 0; i <= 10; i++) /* <= yuzunden 11 eleman yaziliyor */
        a[i] = i;
    free(a);
    return 0;
}
