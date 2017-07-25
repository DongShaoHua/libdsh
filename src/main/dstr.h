//
// Created by dongsh on 7/24/17.
//

#ifndef LIBDSH_DSTR_H
#define LIBDSH_DSTR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * dstr;

typedef struct dstrst {
    size_t length;
    size_t free;
    char buffer[];
} dstrst;

dstr dstr_init(const char *string);
void dstr_release(dstr string);

dstr trim(dstr string);
dstr ltrim(dstr string);
dstr rtrim(dstr string);

#endif //LIBDSH_DSTR_H
