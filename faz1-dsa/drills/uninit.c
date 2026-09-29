/* TATBIKAT 4: ilklendirilmemis degeri kullanma.
 * Ipucu: araclardan biri bunu yakalar, digeri yakalamaz. Neden? */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a = malloc(4 * sizeof *a);
    a[0] = 1;
    a[1] = 2;
    /* a[2] hic yazilmadi */
    if (a[2] > 0)
        printf("pozitif\n");
    else
        printf("pozitif degil\n");
    free(a);
    return 0;
}
