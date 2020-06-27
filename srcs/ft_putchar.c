#include "srcs/libftprintf.h"

int ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}