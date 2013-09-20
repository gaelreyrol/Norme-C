/*
**  @@ScriptName: list.c
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/list.h"
#include "includes/main.h"

void	add_line_list(t_content **content, char *data)
{
	t_content *element = malloc(sizeof(t_content));
	if (!element)
		return (EXIT_FAILURE);
	element->line = data;
	element->next = *content;
	*content = element;
}

void	add_reason_list(t_reason **reason, char *data)
{
	t_reason *element = malloc(sizeof(t_reason));
	if (!element)
		return (EXIT_FAILURE);
	element->reason = data;
	element->next = *reason;
	*reason = element;
}

void	view_reason_list(t_reason *reason)
{
	while (reason)
	{
		ft_putstr(reason->data);
		reason = reason->next;
	}
}

void	clear_reason_list(t_reason **reason)
{
	t_reason	*temp;
	while (*reason)
	{
		temp = *reason->next;
		free(*reason);
		*reason = temp;
	}
}

void	clear_content_list(t_content **content)
{
	t_content	*temp;
	while (*content)
	{
		temp = *content->next;
		free(*content);
		*content = temp;
	}
}
