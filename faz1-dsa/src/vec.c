#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/vec.h"

void vec_init(Vec *v)
{
  v->data = NULL;
  v->cap = 0;
  v->len = 0;
}

bool vec_push(Vec *v, int x)
{
  if (v->data == NULL)
  {
    int *new_data = malloc(sizeof(int) * 4);
    if (new_data == NULL)
      return false;
    v->data = new_data;
    v->data[0] = x;
    v->len = 1;
    v->cap = 4;
    return true;
  }
  else if (v->cap == v->len)
  {
    // yer acilmasi lazim
    size_t newCap = v->cap * 2;
    int *newData = realloc(v->data, sizeof(int) * newCap);
    if (newData == NULL)
      return false;
    v->cap = newCap;
    v->data = newData;
    v->data[v->len] = x;
    v->len += 1;
    return true;
  }
  else if (v->cap > v->len)
  {
    v->data[v->len] = x;
    v->len += 1;
    return true;
  }
  return false;
}

bool vec_get(const Vec *v, size_t i, int *out)
{
  if (i >= v->len)
    return false;
  *out = v->data[i];
  return true;
}

bool vec_set(Vec *v, size_t i, int x)
{
  if (i >= v->len)
    return false;
  v->data[i] = x;
  return true;
}

bool vec_pop(Vec *v, int *out)
{
  if (v->len == 0)
    return false;

  *out = v->data[v->len - 1];
  v->len--;

  return true;
}

void vec_free(Vec *v)
{
  free(v->data);
  v->data = NULL;
  v->cap = 0;
  v->len = 0;
}
