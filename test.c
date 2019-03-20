#include "libft.h"
#include <stdio.h>
#include <limits.h>

#define TEST(...) \
	printf( __VA_ARGS__);\
	printf("\n");\
	fflush(0);\
	ft_printf(__VA_ARGS__);\
	printf("\n");\
	printf("------------------\n");

int		main(void)
{
	int i = 24;
	int j = 0;
//	while (j++ < 500)
		ft_printf("je suis une licorne %+20f %i\n", 10.99989971, i);

	   int             nb;
        nb = 0;
        TEST("space% d ", nb);
        TEST("plus:%+d ", nb);
        TEST("precision:%.5d ", nb);
        TEST("space + prec:% .5d ", nb);
        TEST("Plus + prec / grande:%+.5d ", nb);
        TEST("Prec + 0:%0.5d ", nb);
        TEST("Prec + minus:%-.5d ", nb);
        TEST("size:%5d ", nb);
        TEST("size + space:% 5d ", nb);
        TEST("size + plus:%+5d ", nb);
        TEST("size + minus:%-5d ", nb);
        TEST("size + 0:%05d ", nb);
        TEST("size + 0 + plus:%+05d ", nb);
        TEST("size + 0 + plus:%0+5d ", nb);
        TEST("size + 0 + prec:%05.3d ", nb);
        TEST("size + minus + prec:%-5.3d ", nb);
        TEST("size + plus + 0 + prec:%+05.3d ", nb);
        TEST("size + espace + zero + prec:%0 5.3d ", nb);
        TEST("size + espace + zero + prec:% 05.3d ", nb);
        TEST("size + minus + plus + prec:%-+5.3d ", nb);
}
