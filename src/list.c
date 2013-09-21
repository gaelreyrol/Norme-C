/*
**  @@ScriptName: list.c
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/main.h"
#include "includes/tools.h"
#include "includes/list.h"

void	add_line_list(t_content **content, char *data)
{
	t_content *element;

	element = malloc(sizeof(t_content));
	if (!element)
		return ;
	element->line = data;
	element->next = *content;
	*content = element;
}

void	add_reason_list(t_reason **reason, char *data)
{
	t_reason *element;

	element = malloc(sizeof(t_reason));
	if (!element)
		return ;
	element->reason = data;
	element->next = *reason;
	*reason = element;
}

void	view_reason_list(t_file *file, t_reason *reason)
{
	while (reason)
	{
        ft_putstr("norme: ");
        ft_putstr(file->name);
        ft_putstr(": ");
        ft_print_color(reason->reason, RED);
		reason = reason->next;
	}
}

void	view_content_list(t_content *content)
{
	while (content)
	{
        ft_putstr(content->line);
		content = content->next;
	}
}

void	clear_reason_list(t_reason **reason)
{
	t_reason	*temp;
	while (*reason)
	{
		temp = (*reason)->next;
		free(*reason);
		*reason = temp;
	}
}

void	clear_content_list(t_content **content)
{
	t_content	*temp;
	while (*content)
	{
		temp = (*content)->next;
		free(*content);
		*content = temp;
	}
}
