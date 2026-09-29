/* M5 - Ifadeler (yigit uygulamalari). SPESIFIKASYON: degistirme.
 * expr.c stack.c'yi kullanir: Makefile'da DEPS_expr := src/stack.c */
#ifndef EXPR_H
#define EXPR_H

#include <stdbool.h>
#include <stddef.h>

/* (), [] ve {} dengeli mi? Diger karakterler yok sayilir. */
bool expr_balanced(const char *s);

/* Infix -> postfix.
 * Islenenler: tek karakterlik harf ya da rakam. Operatorler: + - * / ^
 * Oncelik: ^ en yuksek, sonra * /, sonra + -. ^ saga baglidir, digerleri sola.
 * Parantez desteklenir, bosluklar yok sayilir. Tekli (unary) eksi YOK.
 * Sonuc out'a null ile biten dize olarak yazilir.
 * out yetmezse ya da ifade hataliysa (dengesiz parantez, bilinmeyen karakter) false. */
bool expr_to_postfix(const char *infix, char *out, size_t cap);

/* Postfix degerlendirme. Islenenler tek rakam (0-9). Operatorler: + - * / ^
 * (/ tam sayi bolmesi). Sifira bolme, eksik islenen ya da artan islenen: false. */
bool expr_eval_postfix(const char *postfix, long *result);

#endif
