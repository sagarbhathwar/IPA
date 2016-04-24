#include "ipz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//Initialize the 'ipz_t' type variable
//This should be called on every variable
void
ipz_init(ipz_t* x)
{
    *x = malloc(sizeof(struct ipz));
}

//Another way of initalizing ipz_t variable
ipz_t
ipz_init2()
{
    ipz_t x = malloc(sizeof(struct ipz));
    return x;
}

//Initialize the ipz_t's number field using a string type
void
ipz_init_set_str(ipz_t x, const string s)
{
    int l = strlen(s);
    x->number_of_digits = l;
    x->number = calloc(l+1, sizeof(char));
    memcpy(x->number, s, l);
}

//Print the ipz_t variable on stdout
void
ipz_printf(ipz_t x)
{
    printf("%s\n", x->number);
}


void
ipz_prepend_zeroes(string number, int n)
{
    int l = strlen(number);
	string __tmp = calloc(n + l + 1, sizeof(char));
	memset(__tmp, '0', n);
	strcat(__tmp, number);
	strcpy(number, __tmp);
}

void
ipz_add(ipz_t sum, const ipz_t augend, const ipz_t addend)
{
    int l1 = strlen(augend->number);
    int l2 = strlen(addend->number);
    int c = 0;
	if((augend->number)[0] == '9' || (addend->number)[0] == '9')
	{
		string __tmp1 = calloc(l1 + 1, sizeof(char));
		string __tmp2 = calloc(l2 + 1, sizeof(char));
		memcpy(__tmp1, (augend->number), l1 + 1);
		memcpy(__tmp2, (addend->number), l2 + 1);
		if(l1 > l2) ipz_prepend_zeroes(__tmp2, l1 - l2);
        else ipz_prepend_zeroes(__tmp1, l2 - l1);

		printf("%s\n%s\n", __tmp1, __tmp2);
        int l = strlen(__tmp1);

		(sum->number) = calloc(l+2, sizeof(char));
		sum->number[l + 1] = '\0';
		int c = 0;
		for(int i = l - 1; i >= 0; --i)
		{
			int t = (__tmp1[i] - '0') + (__tmp2[i] - '0') + c;
			c = t / 10;
			(sum->number)[i + 1] = (t % 10) + '0' ;
		}
		if(c != 0) (sum->number)[0] = c + '0';
		else ++(sum->number);
	}

	else if(l1 > l2)
	{
		(sum->number) = calloc(l1 + 1, sizeof(char));
		sum->number[l1] = '\0';
		for(int i = l2 - 1; i >=0; --i)
		{
			int t = ((addend->number)[i] - '0') + ((augend->number)[i + l1 - l2] - '0') + c;
			c = t / 10;
			(sum->number)[i + l1 - l2] = (t % 10) + '0' ;
		}
		(sum->number)[l1 - l2 - 1] = (((augend->number)[l1 - l2 - 1] - '0') + c) + '0';
		memcpy((sum->number), (augend->number), l1 - l2 - 1);
	}

	else if(l2 > l1)
	{
		(sum->number) = calloc(l2 + 1, sizeof(char));
		sum->number[l2] = '\0';
		for(int i = l1 - 1; i >=0; --i)
		{
			int t = ((augend->number)[i] - '0') + ((addend->number)[i + l2 - l1] - '0') + c;
			c = t / 10;
			(sum->number)[i + l2 - l1] = (t % 10) + '0' ;
		}
		(sum->number)[l2 - l1 - 1] = (((addend->number)[l2 - l1 - 1] - '0') + c) + '0';
		memcpy((sum->number), (addend->number), l2 - l1 - 1);
	}

	else
	{
		(sum->number) = calloc(l1 + 2, sizeof(char));
		sum->number[l1 + 1] = '\0';
		for(int i = strlen((augend->number)) - 1; i >= 0; --i)
		{
			int t = ((augend->number)[i] - '0') + ((addend->number)[i] - '0') + c;
			c = t / 10;
			(sum->number)[i + 1] = (t % 10) + '0' ;
		}
		if(c != 0) (sum->number)[0] = c + '0';
		else ++(sum->number);
	}
}
