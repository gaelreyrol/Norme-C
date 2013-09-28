/*
**  @@ScriptName: main.c
**  @@Project: Norme-c
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/main.h"
#include "includes/filedesc.h"
#include "includes/scan.h"
#include "includes/tools.h"
#include "includes/regex.h"
#include "includes/list.h"

void    scan(char *file_name)
{
	t_file  file;
	t_list_content *t;
	t_list_reason *r;

	t = malloc(sizeof(t_list_content));
	r = malloc(sizeof(t_list_reason));
	file.name = file_name;
	init_lists(t, r);
	get_extension(&file, r);
	if (file.is_valid)
	{
		if (ft_open_file(&file, t))
		{
			ft_print_name(file.name);
			scan_file_type(&file, t, r, file.extension);
		}
	}
	view_reason_list(&file, r);
	clear_reason_list(r);
}

void	help(void)
{
	ft_putstr("Usage : file_name.(c/h)\n");
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		help();
	else
	{
		while (i < argc)
		{
			scan(argv[i]);
			i++;
		}
	}
	return (0);
}
