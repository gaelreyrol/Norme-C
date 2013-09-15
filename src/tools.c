/*
**  @@ScriptName: tools.c
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/tools.h"

void	ft_print_name(char *name)
{
	ft_putstr("==> ");
	ft_putstr(name);
	ft_putstr(" <==\n");
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

void    ft_putnbr(int nb)
{
    if (nb > INT_MAX || nb < INT_MIN)
        return ;
    if (nb < 0)
    {
        ft_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    else
    {
        ft_putchar(nb + '0');
    }
}
