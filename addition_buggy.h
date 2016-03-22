#ifndef ADDITION_H
#define ADDITION_H
#include <stdlib.h>
#include <string.h>

typedef char* ipz_t;
typedef char digit;

ipz_t ipz_add(ipz_t op1, ipz_t op2)
{
	int l1 = strlen(op1);
	int l2 = strlen(op2);
	int c = 0;
	ipz_t result;
	if(l1 > l2)
	{
		result = calloc(l1, sizeof(digit));
		for(int i = l2 - 1; i >=0; --i)
		{
			int t = (op2[i] - '0') + (op1[i + l1 - l2] - '0') + c;
			c = t / 10;
			result[i + l1 - l2] = (t % 10) + '0' ;
		}
		result[l1 - l2 - 1] = ((op1[l1 - l2 - 1] - '0') + c) + '0';
		memcpy(result, op1, l1 - l2 - 1);
	}
	
	else if(l2 > l1)
	{
		result = calloc(l2, sizeof(digit));
		for(int i = l1 - 1; i >=0; --i)
		{
			int t = (op1[i] - '0') + (op2[i + l2 - l1] - '0') + c;
			c = t / 10;
			result[i + l2 - l1] = (t % 10) + '0' ;
		}
		result[l2 - l1 - 1] = ((op2[l2 - l1 - 1] - '0') + c) + '0';
		memcpy(result, op2, l2 - l1 - 1);
	}
	
	else
	{
		result = calloc(l1 + 1, sizeof(digit));
		for(int i = strlen(op1) - 1; i >= 0; --i)
		{
			int t = (op1[i] - '0') + (op2[i] - '0') + c;
			c = t / 10;
			result[i + 1] = (t % 10) + '0' ;
		}
		if(c != 0)
			result[0] = c + '0';
		else
			result++;
	}
	return result;
}

#endif