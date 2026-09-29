/* Olcum yardimcisi. Benchmark dosyalarinda kullan. */
#ifndef BENCH_H
#define BENCH_H

#include <time.h>

/* Monoton saat: saniye cinsinden (ondalikli). Iki cagri arasindaki fark
 * gecen sureyi verir. Sistem saati degisse bile geri gitmez. */
static inline double now_seconds(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

/* Derleyicinin "sonucu kullanilmiyor" diye olculen kodu silmesini engeller:
 * olctugun hesabin sonucunu buna ver. */
static volatile long long bench_sink;
static inline void bench_keep(long long x) { bench_sink += x; }

#endif
