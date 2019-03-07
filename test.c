#include "libft.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("% 2.55lld\n", 25);
	printf("%-f\n", -25.);
	printf("%+d\n", 25);
	printf("%05d\n", 25);
	printf("%#f\n", 25.);
	printf("% d\n", 25);
}
