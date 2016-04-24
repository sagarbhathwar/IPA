#include "util.h"
#include "ipz.h"
#include <stdlib.h>
#include <string.h>

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
		ipz_t zero = ipz_init();
		ipz_init_set_str(zero, "0");
		first_part->digits = zero->digits;
		second_part->digits = source->digits;
		return;
	}
	first_part->number_of_digits = 2 * (source->number_of_digits);
	second_part->number_of_digits = (source->number_of_digits) - first_part->number_of_digits;
	first_part->digits = source->digits;
	second_part->digits = source->digits + first_part->number_of_digits;
}