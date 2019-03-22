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
	unsigned int		nb = 4080;
	while (j++ < 500)
		ft_printf("Je suis une licorne %d\n", nb);
}
