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
	ft_printf("je suis une licorne %+20f %i\n", 10.99989971, i);
}
