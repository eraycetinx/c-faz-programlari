/* M7 - AVL agaci. SPESIFIKASYON: degistirme.
 * height alani: yaprak 0 (CLRS kurali; Abdul Bari yapraga 1 der). */
#ifndef AVL_H
#define AVL_H

#include <stdbool.h>
#include <stddef.h>

typedef struct ANode {
    int key;
    int height;
    struct ANode *left;
    struct ANode *right;
} ANode;

bool avl_insert(ANode **root, int key);      /* tekrar varsa false; LL, LR, RR, RL rotasyonlari */
bool avl_contains(const ANode *root, int key);
bool avl_delete(ANode **root, int key);      /* ISTEGE BAGLI: yazmazsan testlerde cagirma */
int avl_height(const ANode *root);           /* bos -1 */
/* Tum agaci dogrular: BST sirasi, her dugumde height alani dogru,
 * her dugumde |sol yukseklik - sag yukseklik| <= 1. */
bool avl_check(const ANode *root);
size_t avl_inorder(const ANode *root, int *out, size_t cap);
void avl_free(ANode **root);

#endif
