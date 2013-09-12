/*
**  @@ScriptName: fildesc.c
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/main.h"
#include "includes/filedesc.h"
#include "includes/tools.h"

int	ft_open_file(t_file *norme, char *file)
{
    int	fd;

    fd = open(file, O_RDWR);
    if (fd == -1)
    {
    	print_errno(file);
    	return (0);
    }
    return (1);
}

void	print_errno(char *file)
{
	ft_putstr("norme: ");
	ft_putstr(file);
	if (errno == EACCES)
		ft_putstr(": Permission denied\n");
	if (errno == ENOENT)
		ft_putstr(": No such file or directory\n");
	if (errno == EISDIR)
		ft_putstr(": Is a directory\n");
}
