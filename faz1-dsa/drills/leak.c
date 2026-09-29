/* TATBIKAT 1: bellek sizintisi. Hangi arac yakalar? */
#include <stdlib.h>
#include <string.h>

static char *kopya(const char *s) {
    char *p = malloc(strlen(s) + 1);
    strcpy(p, s);
    return p;
}

int main(void) {
    for (int i = 0; i < 3; i++) {
        char *s = kopya("merhaba");
        (void)s; /* free edilmiyor */
    }
    return 0;
}
