#include "libft.h"
#include <stdio.h>
#include <limits.h>

#define TEST(x, ...) \
	printf(x, __VA_ARGS__);\
	/*printf("\n");*/\
	fflush(0);\
	ft_printf(x, __VA_ARGS__);\
	/*printf("\n")*/;

int		main(void)
{
	int i = 24;
	TEST("je suis une licorne %.7f %i\n", -10.99999971, i);
}
