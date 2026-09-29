/* M6 - Ikili arama agaci. SPESIFIKASYON: degistirme. Tekrarlayan anahtar yok. */
#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct BNode {
    int key;
    struct BNode *left;
    struct BNode *right;
} BNode;

bool bst_insert(BNode **root, int key);        /* iteratif; anahtar zaten varsa false */
bool bst_insert_rec(BNode **root, int key);    /* ozyinelemeli */
bool bst_contains(const BNode *root, int key);
bool bst_delete(BNode **root, int key);        /* iki cocuklu dugumde inorder ardil kullanilir; yoksa false */
bool bst_min(const BNode *root, int *out);
bool bst_max(const BNode *root, int *out);
bool bst_successor(const BNode *root, int key, int *out);  /* key'den buyuk en kucuk anahtar; yoksa false */
BNode *bst_from_preorder(const int *pre, size_t n);        /* O(n), yigitla */
size_t bst_inorder(const BNode *root, int *out, size_t cap);
int bst_height(const BNode *root);             /* bos -1, tek dugum 0 */
void bst_free(BNode **root);                   /* *root = NULL */

#endif
