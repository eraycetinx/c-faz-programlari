/* M8 - Dizi uzerinde max-heap ve heapsort. SPESIFIKASYON: degistirme.
 * Indeksler 0 tabanli: sol = 2i+1, sag = 2i+2, ebeveyn = (i-1)/2.
 * (Abdul Bari 1 tabanli anlatir; formuller buna gore degisir.) */
#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#include <stddef.h>

void heap_build(int *a, size_t n);             /* asagidan yukari heapify: O(n) */
void heap_build_by_insert(int *a, size_t n);   /* tek tek ekleyerek: O(n log n) */
bool heap_is_max_heap(const int *a, size_t n);
void heap_sort(int *a, size_t n);              /* yerinde, artan sira */

#endif
