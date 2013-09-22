/*
**  @@ScriptName: list.c
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/main.h"
#include "includes/tools.h"
#include "includes/list.h"

void	init_content_list(t_list_content *t)
{
	t->first = NULL;
	t->last = NULL;
}

void	add_line_list(t_list_content *t, char *data)
{
	t_content *element;

	element = malloc(sizeof(t_content));
	if (!element)
		return ;
	element->line = data;
	element->next = t->first;
	element->prev = t->last;
	if (t->first)
		t->first->prev = element;
	else
		t->last = element;
	t->first = element;
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

void	view_content_list(t_list_content *t)
{
	t_content *content = t->last;
	while(content)
	{
		ft_putstr(content->line);
		content = content->prev;
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

void	clear_content_list(t_list_content *t)
{
	t_content *element;
	t_content *f_element;

	f_element = t->first;
	while (f_element)
	{
		element = f_element;
		f_element = f_element->next;
		free(element);
	}
	t->first = NULL;
	t->last = NULL;
}
