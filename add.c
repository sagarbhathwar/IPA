#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ZERO 48
#define TRUE 1
#define FALSE 0

struct number_ {
	char* digits;
	int number_of_digits;
};

typedef struct number_* number;

void initialize_number(number input_number, char * digits) {
	int number_of_digits = strlen(digits);
	int offset = 0;
	char *pointer = digits;
	while(*(pointer + 1) != '\0' && *pointer == '0') {
		pointer = pointer + 1;
		offset = offset + 1;
	}
	int effective_number_of_digits = number_of_digits - offset;
	input_number -> digits = malloc(effective_number_of_digits * sizeof(char));
	for(int index = offset, input_number_index = 0; index < number_of_digits; index = index + 1, input_number_index = input_number_index + 1)
		input_number -> digits[input_number_index] = digits[index] - ZERO;
	input_number -> number_of_digits = effective_number_of_digits;
}

void add_numbers(number sum, number first_number, number second_number) {
	int maximum_digits = ((first_number -> number_of_digits > second_number -> number_of_digits) ?
			       first_number -> number_of_digits : second_number -> number_of_digits) + 1;
	char *sum_digits = (char*)(malloc(maximum_digits * sizeof(char)));
	sum_digits[0] = 0;
	int first_number_index = first_number -> number_of_digits - 1;
	int second_number_index = second_number -> number_of_digits - 1;
	int third_number_index = maximum_digits - 1;
	char carry = 0;
	char computed_sum = 0;
	while(first_number_index >= 0 || second_number_index >= 0) {
		computed_sum = 	  (first_number_index >= 0 ? first_number -> digits[first_number_index] : 0)
				+ (second_number_index >= 0 ? second_number -> digits[second_number_index] : 0) + carry;
		sum_digits[third_number_index] = (computed_sum % 10);
		carry = computed_sum / 10;
		--first_number_index;
		--second_number_index;
		--third_number_index;
	}
	sum_digits[third_number_index] = carry;
	int offset = 0;
	if(sum -> digits != NULL)
		free(sum -> digits);
	for(int counter = 0; (counter + 1) != maximum_digits && sum_digits[counter] == 0; ++counter)
		offset = offset + 1;
	int effective_number_of_digits = maximum_digits - offset;
	sum -> digits = malloc(effective_number_of_digits * sizeof(char));
	memcpy(sum -> digits, sum_digits + offset, effective_number_of_digits * sizeof(char));
	sum -> number_of_digits = effective_number_of_digits;
	free(sum_digits);
}

void display(number input_number, char *message) {
	printf("%s = ", message);
	for(int counter = 0; counter < input_number -> number_of_digits; counter++)
		printf("%d", input_number -> digits[counter]);
	printf("\n");
}

int main()
{
	number n1;
	number n2;
	number n3;
	initialize_number(n1, "99999");
	initialize_number(n2, "99999");
	add_numbers(n3, n1, n2);
	display(n3, " ");
}
