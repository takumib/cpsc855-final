#ifndef __NAIVE_MALLOC_H__
#define __NAIVE_MALLOC_H__

#include <stdlib.h>

void *salloc(size_t size);
void *scalloc(int n, size_t size);
void sfree(void *ptr);
void examine_blocks();

#endif
