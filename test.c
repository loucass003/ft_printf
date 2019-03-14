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
	TEST("je suis une licorne %*.*d %i\n", 5, 3, i, i);


	TEST("%.0s\n", "");
	TEST("%.0s\n", NULL);
	TEST("%.0s\n", "Okalm");
	TEST("%.0s\n", "asd34a");
}
