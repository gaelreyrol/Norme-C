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
#include "includes/list.h"

int		is_valid(t_file *file)
{
	if (!file || !file->is_valid)
		return (0);
	return (1);
}

void	get_extension(t_file *file, t_reason **reason)
{
	if (regex(file->name, "(\\.c$)"))
		file->extension = 'c';
	else if (regex(file->name, "(\\.h$)"))
		file->extension = 'h';
	else
	{
		file->is_valid = 0;
		add_reason_list(reason, "Bad extension file\n");
	}
}

int		check_integrity_header(t_list_content *t, t_reason **reason)
{
	t_content *content;
	int is_corrupted;
	int	i;

	content = t->last;
	is_corrupted = 0;
	i = 0;
	while (i < head_height && content)
	{
		if ((!regex(content->line, "(\\*/\n$)")) || (!regex(content->line, "(^/\\*)")) || (strlen(content->line) > 81))
			is_corrupted = 1;
		content = content->prev;
		i++;
	}
	t->last = content;
	if (is_corrupted)
	{
		add_reason_list(reason, "Corrupted header\n");
		return (0);
	}
	return (1);
}

void	scan_file_type(t_file *file, t_list_content *t, t_reason **reason, char type)
{
	switch (type)
	{
		case 'c':
			scan_c_file(file, t, reason);
			break;
		case 'h':
			scan_h_file(file, t, reason);
			break;
		default:
			break;
	}
}

void	scan_c_file(t_file *file, t_list_content *t, t_reason **reason)
{
	t_content *content;

	content = t->last;
	if (!check_integrity_header(t, reason))
		file->is_valid = 0;
	while(content)
	{
		content = content->prev;
	}
}

void	scan_h_file(t_file *file, t_list_content *t, t_reason **reason)
{
	t_content *content;

	content = t->last;
	if (!check_integrity_header(t, reason))
		file->is_valid = 0;
	while(content)
	{
		content = content->prev;
	}
}
