/*
**  @@ScriptName: scan.c
**  @@Project: Norme-c
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/main.h"
#include "includes/scan.h"
#include "includes/regex.h"
#include "includes/tools.h"

int		is_valid(t_file *norme)
{
	if (!norme || !norme->is_valid)
		return (0);
	return (1);
}

void	get_extension(t_file *norme, char *file)
{
	if (regex(file, "(\\.c$)") == 0)
		norme->extension = 'c';
	else if (regex(file, "(\\.h$)") == 0)
		norme->extension = 'h';
	else
	{
		norme->is_valid = 0;
		ft_putstr("norme: ");
		ft_putstr(file);
		norme->reason = " - Bad extension file\n";
	}
}

int		check_line_length(t_file *norme, char *line)
{
	int	i;

	i = 0;
	while (line[i] != EOL)
	{
		if (line[i] == '\t')
			i += 4;
		else
			i++;
	}
	if (i > line_max)
	{
		norme->is_valid = 0;
		norme->reason = "ligne de plus 80 caractères";
		return (0);
	}
	return (1);
}

/*void    ft_scan_file(t_file *norme, char *file)
{
    
}*/
