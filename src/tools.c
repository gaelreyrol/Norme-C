/*
**  @@ScriptName: tools.c
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/tools.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}
