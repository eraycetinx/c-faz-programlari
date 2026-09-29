/* M2 - Karmasiklik sayaclari. SPESIFIKASYON: degistirme.
 * Her fonksiyon, tarif edilen dongu yapisinda "temel islem" sayisini
 * gercekten sayarak (formul kullanmadan) dondurur. */
#ifndef CPLX_H
#define CPLX_H

typedef unsigned long long ull;

ull ops_constant(ull n);   /* her zaman 1 */
ull ops_log(ull n);        /* n > 1 oldukca n = n / 2; adim sayisi. ops_log(1) = 0 */
ull ops_linear(ull n);     /* for i < n */
ull ops_nlogn(ull n);      /* for i < n { ops_log(n) kadar ic adim } */
ull ops_quadratic(ull n);  /* for i < n, for j < n */
ull ops_triangle(ull n);   /* for i < n, for j < i   -> n(n-1)/2 */

#endif
