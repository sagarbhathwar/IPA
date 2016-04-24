#ifndef IPZ_H
#define IPZ_H

struct ipz
{
	char* digits;
	int number_of_digits;
};

typedef struct ipz* ipz_t;

ipz_t ipz_init();
void ipz_init_set_str(ipz_t x, const char* s);
void ipz_printf(ipz_t x);
void ipz_copy(ipz_t destination, ipz_t source);
int ipz_compare(int m, int n);

void ipz_add(ipz_t sum, ipz_t augend, ipz_t addend);
void ipz_sub(ipz_t difference, ipz_t minuend, ipz_t subtrahend);
void ipz_mul(ipz_t product, ipz_t multiplicand, ipz_t multiplier);
void ipz_exp(ipz_t result, ipz_t base, unsigned int power);
void ipz_div(ipz_t quotient, ipz_t divident, ipz_t divisor);

#endif