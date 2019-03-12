#include "libft.h"
#include <stdio.h>
#include <limits.h>

#define TEST(x, ...) \
	printf(x, __VA_ARGS__);\
	fflush(0);\
	ft_printf(x, __VA_ARGS__);

int		main(void)
{
	int i = 0;
	TEST("je suis une licorne %+5.4d %i\n", 500, 42);
}
