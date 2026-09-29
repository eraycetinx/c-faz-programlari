/* M11 - Graf (komsuluk listesi). SPESIFIKASYON: degistirme.
 * Makefile: DEPS_graph := src/queue.c src/stack.c   (Gun 1)
 *           ... src/pq.c                            (Gun 2'de ekle)
 *           ... src/dsu.c                           (Gun 3'te ekle) */
#ifndef GRAPH_H
#define GRAPH_H

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

#define GRAPH_INF LONG_MAX   /* ulasilamayan dugumun uzakligi */

typedef struct Graph Graph;

Graph *graph_create(size_t n, bool directed);   /* dugumler 0..n-1 */
void graph_free(Graph *g);                      /* NULL ile cagrilabilir */
/* Yonsuz grafta kenar iki yonlu eklenir. Komsular EKLENME SIRASIYLA gezilir
 * (boylece BFS/DFS sirasi belirlidir ve test edilebilir). */
bool graph_add_edge(Graph *g, size_t u, size_t v, long w);
size_t graph_vertices(const Graph *g);

/* order en az n elemanlik olmali. Ziyaret sirasini yazar, ziyaret edilen dugum sayisini dondurur. */
size_t graph_bfs(const Graph *g, size_t src, size_t *order);
size_t graph_dfs(const Graph *g, size_t src, size_t *order);       /* ozyinelemeli */
size_t graph_dfs_iter(const Graph *g, size_t src, size_t *order);  /* acik yigitla; sirasi ozyinelemeliyle ayni olmak zorunda degil */

bool graph_topo_sort(const Graph *g, size_t *order);   /* yalnizca yonlu graf; dongu varsa false */
/* dist en az n elemanlik. Negatif agirlikli kenar varsa false. */
bool graph_dijkstra(const Graph *g, size_t src, long *dist);
/* Yonsuz ve bagli graf; degilse false. MST toplam agirligini *total'a yazar. */
bool graph_mst_prim(const Graph *g, long *total);
bool graph_mst_kruskal(const Graph *g, long *total);

#endif
