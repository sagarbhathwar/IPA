#include "ipz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//Initialize the 'ipz_t' type variable
//This should be called on evey variable
void ipz_init(ipz_t* x)
{
    *x = malloc(sizeof(struct ipz));
    x->number = malloc(UINT_MAX*sizeof(digit));
    x->number_of_digits = 0;
}

//Initialize the ipz_t vairable using a string type
void ipz_init_set_str(ipz_t x, const string s)
{
    x->number_of_digits = strlen(s);
    memcpy(x->number, s, x->number_of_digits);
}

//Print the ipz_t variable on stdout
void ipz_printf(ipz_t x)
{
    printf("%s\n", x->number);
}
