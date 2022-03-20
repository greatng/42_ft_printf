#include <stdio.h>
#include "../includes/ft_printf.h"
#include <limits.h>

int	main(void)
{
	printf("test %lx", LONG_MIN);
	ft_printf("Test %x\n", LONG_MIN);
}