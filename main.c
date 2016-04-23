#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "ipz.h"

int main()
{
    ipz_t a;
    ipz_init(a);
    ipz_init_set_str(a, "12345");
    ipz_printf(a);
}
