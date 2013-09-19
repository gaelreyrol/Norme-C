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

int		is_valid(t_file *file)
{
	if (!file || !file->is_valid)
		return (0);
	return (1);
}

void	get_extension(t_file *file)
{
	if (regex(file->name, "(\\.c$)") == 0)
		file->extension = 'c';
	else if (regex(file->name, "(\\.h$)") == 0)
		file->extension = 'h';
	else
	{
		file->is_valid = 0;
		file->reason = "Bad extension file\n";
	}
}
