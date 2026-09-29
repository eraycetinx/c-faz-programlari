/* M2 - Ozyineleme. SPESIFIKASYON: degistirme.
 * Kural: global ya da static degisken YOK (Abdul Bari bazi orneklerde kullanir;
 * burada gereken durum parametreyle tasinir). */
#ifndef RECURSION_H
#define RECURSION_H

#include <stddef.h>

typedef unsigned long long ull;

ull rec_sum(unsigned n);                 /* 1 + 2 + ... + n, ozyinelemeli; rec_sum(0) = 0 */
ull rec_fact(unsigned n);                /* n! , n <= 20; rec_fact(0) = 1 */
ull rec_pow(ull b, unsigned e);          /* b^e, O(log e) carpma; rec_pow(x, 0) = 1 */

/* Fibonacci: fib(0) = 0, fib(1) = 1. */
ull fib_naive(unsigned n, ull *calls);   /* calls NULL degilse her cagrida *calls'u 1 artirir */
ull fib_memo(unsigned n);                /* n <= 93; not tablosu fonksiyon icinde ayrilir ve birakilir */
ull fib_iter(unsigned n);

ull rec_ncr(unsigned n, unsigned r);     /* Pascal ucgeni: C(n,r) = C(n-1,r-1) + C(n-1,r); r > n ise 0 */

/* Hanoi: n diski 'from' cubugundan 'to' cubuguna 'via' uzerinden tasir.
 * Her hamleyi moves[k][0] -> moves[k][1] olarak yazar (en fazla cap hamle).
 * Toplam hamle sayisini dondurur (cap'ten buyuk olabilir; o zaman ilk cap hamle yazilir). */
ull hanoi(unsigned n, int from, int via, int to, int moves[][2], size_t cap);

#endif
