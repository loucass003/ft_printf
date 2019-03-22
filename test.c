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
	unsigned int		nb;
	while (j++ < 500)
		TEST("Je suis une licorne %41d\n", 0)
}
