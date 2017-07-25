//
// Created by dongsh on 7/25/17.
//

#include "testdstr.h"

void test_dstr() {
    dstr string = dstr_init("         What's your name?                        ");

    dstr lstring = ltrim(string);

    dstr rstring = rtrim(string);

    printf("string: %s lstring: %s.\nrstring: %s.\n", lstring, rstring);
}