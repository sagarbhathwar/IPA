#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include "ipz.h"
#define ZERO 48

static ipz_t zero = NULL;

ipz_t
ipz_init()
{
	ipz_t num = malloc(sizeof(struct ipz));
	num->digits = NULL;
	num->number_of_digits = 0;
	return num;
}

void
ipz_init_set_str(ipz_t input, char* digits)
{
	int length = strlen(digits);
	int offset = 0;
	char* ptr = digits;
	while (*(ptr + 1) != '\0' && *ptr == '0') 
	{ 
		++ptr; 
		++offset; 
	}

	int effective_length = length - offset;
	if (input->digits != NULL) free(input->digits);
	input->digits = malloc(effective_length*sizeof(char));
	for (int i = offset, input_index = 0; i < length; ++i, ++input_index) input->digits[input_index] = digits[i] - ZERO;
	input->number_of_digits = effective_length;
}

void
ipz_to_string(ipz_t number, char* num_str)
{
	int i;
	for (i = 0; i < number->number_of_digits; ++i) num_str[i] = number->digits[i] + ZERO;
	num_str[i] = '\0';
}

void
ipz_printf(ipz_t num)
{
	char* str = calloc(num->number_of_digits + 1, sizeof(char));
	ipz_to_string(num, str);
	printf("%s\n", str);
}

void
ipz_copy(ipz_t destination, ipz_t source)
{
	int n = source->number_of_digits;
	int offset = 0;
	char* ptr = source->digits;
	while ((ptr + 1) != (source->digits + n) && *ptr == 0) 
	{ 
		++offset; 
		++ptr; 
	}
	if (destination->digits != NULL) free(destination->digits);
	int effective_length = n - offset;
	destination->digits = malloc(effective_length*sizeof(char));
	memcpy(destination->digits, ptr, effective_length*sizeof(char));
	destination->number_of_digits = effective_length;
}

void
append_zeroes(ipz_t input, unsigned int n)
{
	if (input->number_of_digits == 1 && input->digits[0] == 0) return;

	input->digits = realloc(input->digits, (n + input->number_of_digits)*sizeof(char));
	memset(input->digits + input->number_of_digits, 0, n*sizeof(char));
	input->number_of_digits = input->number_of_digits + n;
}

void
split(ipz_t source, ipz_t first_part, ipz_t second_part, int length)
{
	if (source->number_of_digits == 1 || source->number_of_digits < length)
	{
		first_part->number_of_digits = 1;
		second_part->number_of_digits = source->number_of_digits;
		first_part->digits = zero->digits;
		second_part->digits = source->digits;
		return;
	}
	first_part->number_of_digits = (source->number_of_digits) / 2;
	second_part->number_of_digits = (source->number_of_digits) - first_part->number_of_digits;
	first_part->digits = source->digits;
	second_part->digits = source->digits + first_part->number_of_digits;
}

uint32_t
previous_power_of_2(uint32_t x)
{
	x = x | (x >> 1);
	x = x | (x >> 2);
	x = x | (x >> 4);
	x = x | (x >> 8);
	x = x | (x >> 16);
	return x - (x >> 1);
}

void
ipz_add(ipz_t sum, ipz_t augend, ipz_t addend)
{
	int max_digits =
		(augend->number_of_digits > addend->number_of_digits ?
		augend->number_of_digits
		:
		addend->number_of_digits)
		+ 1;
	
	char* result = malloc(max_digits*sizeof(char));
	result[0] = 0;
	int augend_index = augend->number_of_digits - 1;
	int addend_index = addend->number_of_digits - 1;
	int result_index = max_digits - 1;
	char carry = 0;
	while (augend_index >= 0 || addend_index >= 0)
	{
		char computed_sum =
			(augend_index >= 0 ? augend->digits[augend_index] : 0)
			+
			(addend_index >= 0 ? addend->digits[addend_index] : 0)
			+ 
			carry;
		result[result_index] = computed_sum % 10;
		carry = computed_sum / 10;
		--augend_index;
		--addend_index;
		--result_index;
	}
	result[result_index] = carry;
	int offset = 0;
	if (sum->digits != NULL) free(sum->digits);
	for (int i = 0; (i + 1) != max_digits && result[i] == 0; ++i) ++offset;
	int effective_length = max_digits - offset;
	sum->digits = malloc(effective_length*sizeof(char));
	memcpy(sum->digits, result + offset, effective_length*sizeof(char));
	sum->number_of_digits = effective_length;
	free(result);
}

void
ipz_sub(ipz_t difference, ipz_t minuend, ipz_t subtrahend)
{
	int max_digits = ((minuend->number_of_digits > subtrahend->number_of_digits) 
		?
		minuend->number_of_digits 
		: 
		subtrahend->number_of_digits);
	char* result = (malloc((max_digits + 1)*sizeof(char)));
	int minuend_index = minuend->number_of_digits - 1;
	int subtrahend_index = subtrahend->number_of_digits - 1;
	int result_index = max_digits - 1;
	bool has_borrow = false;
	while (minuend_index >= 0) 
	{
		char diff = 
			minuend->digits[minuend_index] 
			- 
			(subtrahend_index >= 0 ? subtrahend->digits[subtrahend_index] : 0)
			- 
			(has_borrow ? 1 : 0);

		if (diff >= 0) has_borrow = false;
		else 
		{ 
			has_borrow = true; 
			diff += 10; 
		}
		result[result_index] = diff;
		--minuend_index;
		--subtrahend_index;
		--result_index;
	}
	int offset = 0;
	if (difference->digits != NULL) free(difference->digits);
	for (int i = 0; i + 1 != max_digits && result[i] == 0; ++i) ++offset;
	int effective_length = max_digits - offset;
	difference->digits = malloc(effective_length*sizeof(char));
	memcpy(difference->digits, result + offset, effective_length*sizeof(char));
	difference->number_of_digits = effective_length;
	free(result);
}


ipz_t
_karatsuba_multiplication(ipz_t multiplicand, ipz_t multiplier)
{
	if (multiplicand->number_of_digits == 1 && multiplier->number_of_digits == 1)
	{
		char prod = (multiplicand->digits[0])*(multiplier->digits[0]);
		char prod_first_digit = prod / 10;
		char prod_second_digit = prod % 10;
		ipz_t product = ipz_init();
		product->number_of_digits = prod_first_digit == 0 ? 1 : 2;
		product->digits = malloc((product->number_of_digits)*sizeof(char));
		if (prod_first_digit == 0) product->digits[0] = prod_second_digit;
		else
		{
			product->digits[0] = prod_first_digit;
			product->digits[1] = prod_second_digit;
		}
		return product;
	}

	if ((multiplicand->number_of_digits == 1 && multiplicand->digits[0] == 0) ||
		(multiplier->number_of_digits == 1 && multiplier->digits[0] == 0))
	{
		ipz_t prod = ipz_init();
		ipz_init_set_str(prod, "0");
		return prod;
	}

	ipz_t a1 = ipz_init();
	ipz_t a2 = ipz_init();
	ipz_t b1 = ipz_init();
	ipz_t b2 = ipz_init();
	ipz_t a1_add_a2 = ipz_init();
	ipz_t b1_add_b2 = ipz_init();

	ipz_t largest = 
		(multiplicand->number_of_digits) > (multiplier->number_of_digits) 
		?
		multiplicand 
		: 
		multiplier;

	split(multiplicand, a1, a2, largest->number_of_digits);
	split(multiplier, b1, b2, largest->number_of_digits);

	ipz_add(a1_add_a2, a1, a2);
	ipz_add(b1_add_b2, b1, b2);

	ipz_t p1 = _karatsuba_multiplication(a1, b1);
	ipz_t p2 = _karatsuba_multiplication(a2, b2);
	ipz_t p3 = _karatsuba_multiplication(a1_add_a2, b1_add_b2);

	ipz_t p1_add_p2 = ipz_init();
	ipz_t p3_diff_p2_diff_p1 = ipz_init();

	ipz_add(p1_add_p2, p1, p2);
	ipz_sub(p3_diff_p2_diff_p1, p3, p1_add_p2);

	int num_of_zeroes = largest->number_of_digits - (largest->number_of_digits) / 2;
	append_zeroes(p1, 2 * num_of_zeroes);
	append_zeroes(p3_diff_p2_diff_p1, num_of_zeroes);

	ipz_t final_prod = ipz_init();
	ipz_add(final_prod, p1, p3_diff_p2_diff_p1);
	ipz_add(final_prod, final_prod, p2);

	free(a1);
	free(a2);
	free(b1);
	free(b2);
	free(a1_add_a2);
	free(b1_add_b2);
	free(p1);
	free(p2);
	free(p3);
	free(p1_add_p2);
	free(p3_diff_p2_diff_p1);

	return final_prod;
}

void
ipz_mul(ipz_t product, ipz_t multiplicand, ipz_t multiplier)
{
	zero = ipz_init();
	ipz_init_set_str(zero, "0");
	ipz_t _multiplicand = ipz_init();
	ipz_t _multiplier = ipz_init();
	if (multiplicand == product) ipz_copy(_multiplicand, multiplicand);
	else 
	{
		_multiplicand->number_of_digits = multiplicand->number_of_digits;
		_multiplicand->digits = multiplicand->digits;
	}

	if (multiplier == product) ipz_copy(_multiplier, multiplier);
	else
	{
		_multiplier->number_of_digits = multiplier->number_of_digits;
		_multiplier->digits = multiplier->digits;
	}

	ipz_t _product = _karatsuba_multiplication(_multiplicand, _multiplier);
	product->digits = _product->digits;
	product->number_of_digits = _product->number_of_digits;
	free(_multiplicand);
	free(_multiplier);
	free(_product);
}

void
ipz_exp(ipz_t result, ipz_t base, unsigned int power)
{
	ipz_t _result = ipz_init();
	ipz_copy(_result, base);
	int remaining_count = power - previous_power_of_2(power);
	power = previous_power_of_2(power);
	while (power > 1)
	{
		ipz_mul(_result, _result, _result);
		power /= 2;
	}

	while (remaining_count--) ipz_mul(_result, _result, base);
	result->digits = _result->digits;
	result->number_of_digits = _result->number_of_digits;
	free(_result);
}

int
ipz_compare(ipz_t m, ipz_t n)
{
	if (m->number_of_digits > n->number_of_digits) return 1;

	if (m->number_of_digits < n->number_of_digits) return -1;

	int i = m->number_of_digits - 1;
	while (i >= 0)
	{
		if (m->digits[i] > n->digits[i]) return 1;

		else if (m->digits[i] < n->digits[i]) return -1;

		--i;
	}
	return 0;
}

void
ipz_modulo(ipz_t modulo, ipz_t divident, ipz_t divisor)
{
	ipz_t _divident = ipz_init();
	ipz_copy(_divident, divident);
	while (ipz_compare(_divident, divisor) >= 0) ipz_sub(_divident, _divident, divisor);
	ipz_copy(modulo, _divident);
}