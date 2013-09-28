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

void	get_extension(t_file *file, t_list_reason *r)
{
	if (regex(file->name, "(\\.c$)"))
		file->extension = 'c';
	else if (regex(file->name, "(\\.h$)"))
		file->extension = 'h';
	else
	{
		file->is_valid = 0;
		add_reason_list(r, "Bad extension file\n", 0);
	}
}

int		check_integrity_header(t_list_content *t, t_content *content, t_list_reason *r)
{
	int is_corrupted;
	int	i;

	is_corrupted = 0;
	i = 0;
	while (i < head_height && content)
	{
		if ((strlen(content->line) > 81))
		{
			is_corrupted = 1;
			add_reason_list(r, "Line larger than 80 characters\n", content->line_nbr);
		}
		else if ((!regex(content->line, "(\\*/\n$)")) || (!regex(content->line, "(^/\\*)")))
		{
			is_corrupted = 1;
			add_reason_list(r, "Corrupted header line (must begin by '/*' and finish by '*/')\n", content->line_nbr);
		}
		content = content->prev;
		i++;
	}
	t->last = content;
	if (is_corrupted)
		return (0);
	return (1);
}

void	scan_file_type(t_file *file, t_list_content *t, t_list_reason *r, char type)
{
	switch (type)
	{
		case 'c':
			scan_c_file(file, t, r);
			break;
		case 'h':
			scan_h_file(file, t, r);
			break;
		default:
			break;
	}
}

void	scan_c_file(t_file *file, t_list_content *t, t_list_reason *r)
{
	t_content	*content;
	t_reason	*reason;

	content = t->last;
	reason = r->last;
	if (!check_integrity_header(t, content, r))
		file->is_valid = 0;
	content = t->last;
	while(content)
	{
		content = content->prev;
	}
}

void	scan_h_file(t_file *file, t_list_content *t, t_list_reason *r)
{
	t_content	*content;
	t_reason	*reason;

	content = t->last;
	reason = r->last;
	if (!check_integrity_header(t, content, r))
		file->is_valid = 0;
	content = t->last;
	while(content)
	{
		content = content->prev;
	}
}
