//
// Created by dongsh on 7/24/17.
//

#include "dstr.h"

#define return_label returnlabel:
#define go_return goto returnlabel;
#define match_val "        "

dstr dstr_init(const char *string) {
    dstrst *ds = NULL;

    if (!string) {
        go_return
    }

    size_t length = strlen(string);

    size_t memlen = sizeof(*ds) + length + 1;

    ds = (dstrst *)malloc(memlen);

    if (ds) {
        memset(ds, 0, memlen);
        if (length > 0) {
            ds->length = length;
            strcpy(ds->buffer, string);
            ds->buffer[length] = '\0';
        }
    }

    return_label
    return ds->buffer;
}

void dstr_release(dstr string) {
    if (string) {
        dstrst *ds = (dstrst *)(((long *)string) - 2);
        free(ds);
    }
}

dstr trim(dstr string) {
    dstr temp = ltrim(string);
    dstr result = rtrim(temp);

    if (temp) {
        dstr_release(temp);
        temp = NULL;
    }

    return result;
}

dstr ltrim(dstr string) {
    dstrst *lds = NULL;
    if (string) {

    }

    return lds ? lds->buffer : NULL;
}

dstr rtrim(dstr string) {
    dstrst *rds = NULL;
    if (string) {

    }

    return rds ? rds->buffer : NULL;
}