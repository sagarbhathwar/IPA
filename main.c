#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "ipz.h"

int main()
{
	ipz_t a = ipz_init();
	ipz_t b = ipz_init();
	ipz_t c = ipz_init();
	char* s1 = calloc(10000000, sizeof(char));
	char* s2 = calloc(10000000, sizeof(char));
	scanf("%s %s", s1, s2);
	ipz_init_set_str(a, s1);
	ipz_init_set_str(b, s2);
	ipz_modulo(c, a, b);
	ipz_printf(c);
}
