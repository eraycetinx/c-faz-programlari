/* M6 - Ikili agac. SPESIFIKASYON: degistirme.
 * Yukseklik CLRS kurali: bos agac -1, tek dugum 0.
 * (Abdul Bari tek dugume 1 der; burada CLRS kurali gecerli.) */
#ifndef BTREE_H
#define BTREE_H

#include <limits.h>
#include <stddef.h>

#define BTREE_NULL INT_MIN   /* seviye dizisinde "cocuk yok" isareti */

typedef struct TNode {
    int value;
    struct TNode *left;
    struct TNode *right;
} TNode;

/* Seviye sirali diziden agac kurar. BTREE_NULL bos cocugu isaretler;
 * bos dugumlerin cocuklari diziye YAZILMAZ.
 * Ornek: {1, 2, 3, BTREE_NULL, 4}  ->  kok 1; 1'in cocuklari 2 ve 3;
 *        2'nin sol cocugu yok, sag cocugu 4.
 * n == 0 ya da a[0] == BTREE_NULL ise NULL. */
TNode *btree_from_level(const int *a, size_t n);
void btree_free(TNode *root);

/* Dolasmalar: dugum sayisini dondurur, en fazla cap degeri out'a yazar. */
size_t btree_preorder(const TNode *root, int *out, size_t cap);
size_t btree_inorder(const TNode *root, int *out, size_t cap);
size_t btree_postorder(const TNode *root, int *out, size_t cap);
size_t btree_preorder_iter(const TNode *root, int *out, size_t cap);  /* acik yigitla */
size_t btree_inorder_iter(const TNode *root, int *out, size_t cap);   /* acik yigitla */
size_t btree_levelorder(const TNode *root, int *out, size_t cap);     /* kuyrukla */

size_t btree_count(const TNode *root);
size_t btree_leaves(const TNode *root);
int btree_height(const TNode *root);

#endif
