#ifndef IPZ_H
#define IPZ_H
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
typedef char digit;
struct ipz
{
    string number;
    int number_of_digits;
};

typedef struct ipz* ipz_t;

void ipz_init(ipz_t x);
void ipz_init_set_str(ipz_t x, const string s);
void ipz_printf(ipz_t x);

void ipz_add(ipz_t sum, ipz_t augend, ipz_t addend);

void ipz_sub(ipz_t difference, ipz_t minuent, ipz_t subtrahend);

void ipz_mul(ipz_t product, ipz_t multiplicamd, ipz_t multiplier);

void ipz_div(ipz_t quotient, ipz_t divident, ipz_t divisor);

#endif
