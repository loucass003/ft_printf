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
	TEST("je suis une licorne %-20.5s %i\n", "j aime les licornes", 42);


	TEST("%.0s\n", "");
	TEST("%.0s\n", NULL);
	TEST("%.0s\n", "Okalm");
	TEST("%.0s\n", "asd34a");
}
