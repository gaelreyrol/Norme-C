/*
**  @@ScriptName: scan.c
**  @@Project: Norme-c
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/main.h"
#include "includes/scan.h"

int		is_valid(t_file *norme)
{
	if (!norme || !norme->is_valid)
		return (0);
	return (1);
}

void    ft_scan_file(t_file *norme, char *file)
{
    
}
