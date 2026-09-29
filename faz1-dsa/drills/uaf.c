/* TATBIKAT 3: free edilmis bellegi kullanma (use-after-free). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(sizeof *p);
    *p = 42;
    free(p);
    printf("%d\n", *p); /* p artik gecersiz */
    return 0;
}
