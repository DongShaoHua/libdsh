//
// Created by dongsh on 7/24/17.
//

#include "dstr.h"

#define return_label returnlabel:
#define go_return goto returnlabel;
#define dstr_2_dstrst(string) (dstrst *)(((long *)(string)) - 2)

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
        dstrst *ds = dstr_2_dstrst(string);
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

#define ltrim_check(string, strlength, type, typelength, label, golabel) \
    if ((strlength) >= (typelength)) { \
        label \
        if (*((type *)"        ") == *((type *)string)) { \
            (string) +=  (typelength); \
            (strlength) -=  (typelength); \
        } else { \
            golabel; \
        } \
    } \

dstr ltrim(dstr string) {
    dstrst *lds = NULL;
    if (string) {
        dstrst *ds = dstr_2_dstrst(string);
        size_t length = ds->length;

        size_t long_long_bit = sizeof(long long);
        size_t int_bit = sizeof(int);
        size_t short_bit = sizeof(short);
        size_t char_bit = sizeof(char);

        while (length) {
            ltrim_check(string, length, long long,
                        long_long_bit, , goto int_match_label)

            ltrim_check(string, length, int, int_bit,
                        int_match_label:, goto short_match_label)

            ltrim_check(string, length, short, short_bit,
                        short_match_label:, goto char_match_label)

            ltrim_check(string, length, char, char_bit,
                        char_match_label:, break)
        }

        size_t memlen = sizeof(*lds) + length + 1;
        lds = (dstrst *)malloc(memlen);

        if (lds) {
            memset(lds, 0, memlen);
            if (length > 0) {
                lds->length = length;
                strcpy(lds->buffer, string);
                lds->buffer[length] = '\0';
            }
        }
    }

    return lds ? lds->buffer : NULL;
}

#define rtrim_check(string, strlength, type, typelength, label, golabel) \
    if (strlength >= typelength) { \
        label \
        if (*((type *)"        ") == *((type *)(end - typelength))) { \
            end -= typelength; \
            strlength -= typelength; \
        } else { \
            golabel; \
        } \
    }

dstr rtrim(dstr string) {
    dstrst *rds = NULL;
    if (string) {
        dstrst *ds = dstr_2_dstrst(string);
        size_t length = ds->length;
        dstr end = string + length;
        size_t long_long_bit = sizeof(long long);
        size_t int_bit = sizeof(int);
        size_t short_bit = sizeof(short);
        size_t char_bit = sizeof(char);
        while (length > 0) {
            rtrim_check(end, length, long long,
                        long_long_bit, , goto int_match_label)

            rtrim_check(end, length, int, int_bit,
                        int_match_label:, goto short_match_label)

            rtrim_check(end, length, short, short_bit,
                        short_match_label:, goto char_match_label)

            rtrim_check(end, length, char, char_bit,
                        char_match_label:, break)
        }

        size_t memlen = sizeof(*rds) + length + 1;
        rds = (dstrst *)malloc(memlen);

        if (rds) {
            memset(rds, 0, memlen);
            if (length > 0) {
                rds->length = length;
                strcpy(rds->buffer, string);
                rds->buffer[length] = '\0';
            }
        }
    }

    return rds ? rds->buffer : NULL;
}