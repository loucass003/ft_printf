#include "libft.h"
#include <stdio.h>
#include <limits.h>

#define TEST(...) \
	printf( __VA_ARGS__);\
	/*printf("\n");*/\
	fflush(0);\
	ft_printf(__VA_ARGS__);\
	printf("------------------\n");

int		main(void)
{
	int i = 24;
	int j = 0;
	//while (j++ < 500)
	unsigned int		nb;
	TEST("Je suis une licorne ho ho ho %.5p\n", 0)
}
