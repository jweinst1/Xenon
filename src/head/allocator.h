#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdlib.h>
#include "xenon_def.h"

//static storage functions

XenonStream_d* allo_stat_xs_d_s();

//static storage counter

int allo_stat_xs_d_c(int ad);

//basic allocation functions

void* allo_of_block(size_t block, const int amount);

void* allo_of_code(char code, const int amount);

void* allo_of_size(size_t block);

//dynamic stream allocators
//s means single

XenonStream_d* allo_xs_d_s();

//single allocation of large stream
XenonStream_dl* allo_xs_dl_s();


//basic deallocations

void allo_delete(void* pnt);

void allo_del_xs_d(XenonStream_d* xs);

void allo_del_xs_dl(XenonStream_dl* xs);



#endif