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
/*	int i = 24;
	TEST("je suis une licorne %+20f %i\n", 10.99989971, i);*/
		double		nb;
	nb = -12547.58;

    TEST("space:% f\n", nb);
    TEST("plus:%+f\n", nb);
    TEST("hash:%#f\n", nb);
    TEST("precision:%.2f\n", nb);
    TEST("big prec:%.14f\n", nb);
    TEST("precision + hash:%#.0f\n", nb);
    TEST("space + prec:% .5f\n", nb);
    TEST("space + prec + hash:%# .0f\n", nb);
    TEST("space + prec + hash:% #.0f\n", nb);
    TEST("Plus + prec / grande:%+.5f\n", nb);
    TEST("Plus + prec / petite:%+.0f\n", nb);
    TEST("Plus + prec + hash:%#+.0f\n", nb);
    TEST("Prec + 0:%0.5f\n", nb);
    TEST("Prec + minus:%-.5f\n", nb);
    TEST("size:%5f\n", nb);
    TEST("size + space:% 5f\n", nb);
    TEST("size + plus:%+5f\n", nb);
    TEST("size + space:%# 5f\n", nb);
    TEST("size + plus:%#+5f\n", nb);
    TEST("size + minus:%-5f\n", nb);
    TEST("size + 0:%05f\n", nb);
    TEST("size + 0 + plus:%+05f\n", nb);
    TEST("size + 0 + plus:%0+5f\n", nb);
    TEST("size + 0 + prec:%05.3f\n", nb);
    TEST("size + 0 + prec + hash:%0#5.0f\n", nb);
    TEST("size + minus + prec:%-5.3f\n", nb);
    TEST("size + minus + prec + hash:%-#5.0f\n", nb);
    TEST("size + plus + 0 + prec:%+05.3f\n", nb);
    TEST("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
    TEST("size + espace + zero + prec:%0 5.3f\n", nb);
    TEST("size + espace + zero + prec:% 05.3f\n", nb);
    TEST("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
    TEST("size + minus + plus + prec:%-+5.3f\n", nb);
    TEST("size + minus + plus + prec + hash:%-#+5.0f\n", nb);
}
