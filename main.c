#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "ipz.h"

int main()
{
    ipz_t a = ipz_init2();
    ipz_t b = ipz_init2();
    ipz_t c = ipz_init2();
    //char s1[100000];
    //char s2[100000];
    string s1 = calloc(10000000, sizeof(char));
    string s2 = calloc(10000000, sizeof(char));
    scanf("%s %s", s1, s2);
    ipz_init_set_str(a, s1);
    ipz_init_set_str(b, s2);
    ipz_add(c, a, b);
    ipz_printf(c);
}
