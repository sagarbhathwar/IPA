#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ipz.h"

int main()
{
#if 0
	ipz_t a = ipz_init();
	ipz_t b = ipz_init();
	ipz_t c = ipz_init();
	char* s1 = calloc(10000000, sizeof(char));
	char* s2 = calloc(10000000, sizeof(char));
	scanf("%s %s", s1, s2);
	ipz_init_set_str(a, s1);
	ipz_init_set_str(b, s2);
	clock_t t1 = clock();
	ipz_add(c, a, b);
	clock_t t2 = clock();
	ipz_printf(c);
	printf("Time taken: %lf\n", (double)(t2 - t1)/ CLOCKS_PER_SEC);
#endif

#if 0
	ipz_t a = ipz_init();
	ipz_t b = ipz_init();
	ipz_t c = ipz_init();
	char* s1 = calloc(10000000, sizeof(char));
	char* s2 = calloc(10000000, sizeof(char));
	scanf("%s %s", s1, s2);
	ipz_init_set_str(a, s1);
	ipz_init_set_str(b, s2);
	clock_t t1 = clock();
	ipz_sub(c, a, b);
	clock_t t2 = clock();
	ipz_printf(c);
	printf("Time taken: %lf\n", (double)(t2 - t1)/ CLOCKS_PER_SEC);
#endif

#if 0
	ipz_t a = ipz_init();
	ipz_t b = ipz_init();
	ipz_t c = ipz_init();
	char* s1 = calloc(10000000, sizeof(char));
	char* s2 = calloc(10000000, sizeof(char));
	scanf("%s %s", s1, s2);
	ipz_init_set_str(a, s1);
	ipz_init_set_str(b, s2);
	clock_t t1 = clock();
	ipz_mul(c, a, b);
	clock_t t2 = clock();
	ipz_printf(c);
	printf("Time taken: %lf\n", (double)(t2 - t1)/ CLOCKS_PER_SEC);
#endif

#if 0
	ipz_t a = ipz_init();
	ipz_t b = ipz_init();
	ipz_t c = ipz_init();
	char* s1 = calloc(10000000, sizeof(char));
	char* s2 = calloc(10000000, sizeof(char));
	scanf("%s %s", s1, s2);
	ipz_init_set_str(a, s1);
	ipz_init_set_str(b, s2);
	clock_t t1 = clock();
	ipz_div(c, a, b);
	clock_t t2 = clock();
	ipz_printf(c);
	printf("Time taken: %lf\n", (double)(t2 - t1)/ CLOCKS_PER_SEC);
#endif

#if 0
	ipz_t a = ipz_init();
	ipz_t c = ipz_init();
	char* s1 = calloc(10000000, sizeof(char));
	scanf("%s", s1);
	ipz_init_set_str(a, s1);
	unsigned long long int b;
	scanf("%llu", &b);
	clock_t t1 = clock();
	ipz_div_ui(c, a, b);
	clock_t t2 = clock();
	ipz_printf(c);
	printf("Time taken: %lf\n", (double)(t2 - t1)/ CLOCKS_PER_SEC);
#endif

#if 0
	ipz_t a = ipz_init();
	ipz_t b = ipz_init();
	ipz_t c = ipz_init();
	char* s1 = calloc(10000000, sizeof(char));
	char* s2 = calloc(10000000, sizeof(char));
	scanf("%s %s", s1, s2);
	ipz_init_set_str(a, s1);
	ipz_init_set_str(b, s2);
	clock_t t1 = clock();
	ipz_exp(c, a, b);
	clock_t t2 = clock();
	ipz_printf(c);
	printf("Time taken: %lf\n", (double)(t2 - t1)/ CLOCKS_PER_SEC);
#endif

#if 0
	ipz_t a = ipz_init();
	ipz_t c = ipz_init();
	char* s1 = calloc(10000000, sizeof(char));
	scanf("%s", s1);
	ipz_init_set_str(a, s1);
	unsigned long long int b;
	scanf("%llu", &b);
	clock_t t1 = clock();
	ipz_exp_ui(c, a, b);
	clock_t t2 = clock();
	ipz_printf(c);
	printf("Time taken: %lf\n", (double)(t2 - t1)/ CLOCKS_PER_SEC);
#endif
}
