#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/readings.h"

void readings_init(Readings *r)
{
  r->values = NULL;
  r->count = 0;
  r->cap = 0;
}

bool readings_add(Readings *r, double x)
{
  // liste bos
  if (r->values == NULL)
  {
    // yer ayirildi
    double *cap = malloc(sizeof(double) * 8);
    if (cap == NULL)
    {
      return false;
    }
    r->values = cap;
    r->values[0] = x;
    r->count = 1;
    r->cap = 8;
    return true;
  }
  else if (r->cap == r->count)
  { // r->cap kapasiteyi alir eger eleman sayisini type ile carparsak kaplanan alani bur
    // size dolu
    // 2 katina cikart
    size_t new_cap = r->cap * 2;
    double *new_point = realloc(r->values, sizeof(double) * new_cap);
    if (new_point == NULL)
    {
      return false;
    }
    r->values = new_point;
    r->cap = new_cap;
    r->values[r->count] = x;
    r->count += 1;
    return true;
  }
  else if (r->cap > r->count)
  {
    r->values[r->count] = x;
    r->count += 1;
    return true;
  }
  return false;
}

bool readings_at(const Readings *r, size_t i, double *out)
{
  // istenilen index eleman sayisindan fazladir. return false direkt
  // Ya da i<0 eleman olursa direkt return false;
  if (i >= r->count)
    return false;

  *out = r->values[i];
  return true;
}

bool readings_min(const Readings *r, double *out)
{
  if (r->values == NULL)
    return false;

  // gecici olarak en kucuk ilk eleman olsun.
  *out = r->values[0];
  for (size_t i = 0; i < r->count; i++)
  {
    if (r->values[i] < *out)
    {
      *out = r->values[i];
    }
  }
  return true;
}

bool readings_max(const Readings *r, double *out)
{
  if (r->values == NULL)
    return false;

  // gecici olarak en kucuk ilk eleman olsun.
  *out = r->values[0];
  for (size_t i = 0; i < r->count; i++)
  {
    if (r->values[i] > *out)
    {
      *out = r->values[i];
    }
  }
  return true;
}

void readings_free(Readings *r)
{
  free(r->values);
  r->values = NULL;
  r->cap = 0;
  r->count = 0;
}
