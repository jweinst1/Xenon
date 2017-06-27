#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdlib.h>

//basic allocation functions

void* allo_of_block(size_t block, int amount);

void* allo_of_code(char code, int amount);

void* allo_of_size(size_t block);

//basic deallocation

void allo_delete(void* pnt);

#endif