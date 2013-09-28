/*
**  @@ScriptName: list.c
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/main.h"
#include "includes/tools.h"
#include "includes/list.h"

void	init_lists(t_list_content *t, t_list_reason *r)
{
	t->first = NULL;
	t->last = NULL;

	r->first = NULL;
	r->last = NULL;
}

void	add_line_list(t_list_content *t, char *data, int line_nbr)
{
	t_content *element;

	element = malloc(sizeof(t_content));
	if (!element)
		return ;
	element->line = data;
	element->line_nbr = line_nbr;
	element->next = t->first;
	element->prev = NULL;
	if (t->first)
		t->first->prev = element;
	else
		t->last = element;
	t->first = element;
}

void	add_reason_list(t_list_reason *r, char *data, int line_nbr)
{
	t_reason *element;

	element = malloc(sizeof(t_reason));
	if (!element)
		return ;
	element->reason = data;
	element->line_nbr = line_nbr;
	element->next = r->first;
	element->prev = NULL;
	if (r->first)
		r->first->prev = element;
	else
		r->last = element;
	r->first = element;
}

void	view_reason_list(t_file *file, t_list_reason *r)
{
	t_reason *reason = r->last;
	while (reason)
	{
		ft_putstr("norme: ");
		ft_putstr(file->name);
		if (reason->line_nbr)
		{
			ft_putstr(" - line: ");
			ft_putnbr(reason->line_nbr);
		}
		ft_putstr(" ");
		ft_print_color(reason->reason, RED);
		reason = reason->prev;
	}
}

void	view_content_list(t_list_content *t)
{
	t_content *content = t->last;
	while(content)
	{
		ft_putstr(content->line);
		ft_putnbr(content->line_nbr);
		content = content->prev;
	}
}

void	clear_reason_list(t_list_reason *r)
{
	t_reason	*element;
	t_reason	*f_element;

	f_element = r->first;
	while (f_element)
	{
		element = f_element;
		f_element = f_element->next;
		free(element);
	}
	r->first = NULL;
	r->last = NULL;
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
