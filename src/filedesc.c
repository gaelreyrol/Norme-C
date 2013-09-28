/*
**  @@ScriptName: fildesc.c
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/main.h"
#include "includes/filedesc.h"
#include "includes/tools.h"
#include "includes/list.h"

int		ft_open_file(t_file *file, t_list_content *t)
{
	FILE	*fd;
	int		line_nbr;
	int		read;
	size_t	len;
	char	*line = NULL;

	line_nbr = 1;
	len = 0;
	fd = fopen(file->name, "r");
	if (fd == 0)
	{
		print_errno(file->name);
		return (0);
	}
	while ((read = getline(&line, &len, fd)) != -1)
	{
		add_line_list(t, strdup(line), line_nbr);
		line_nbr++;
	}
	if (fclose(fd) == -1)
		return (0);
	return (1);
}

void	print_errno(char *file_name)
{
	ft_putstr("norme: ");
	ft_putstr(file_name);
	ft_putstr(": ");
	if (errno == EACCES)
		ft_print_color("Permission denied\n", RED);
	if (errno == ENOENT)
		ft_print_color("No such file or directory\n", RED);
	if (errno == EISDIR)
		ft_print_color("Is a directory\n", RED);
}
