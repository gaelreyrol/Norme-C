/*
**  @@ScriptName: list.c
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/main.h"

void	add_line_list(t_content **content, char *data)
{
	t_content *element = malloc(sizeof(t_content));
	if (!element)
		return (EXIT_FAILURE);
	element->line = data;
	element->next_line = *content;
	*content = element;
}

void	add_reason_list(t_reason **reason, char *data)
{
	t_reason *element = malloc(sizeof(t_reason));
	if (!element)
		return (EXIT_FAILURE);
	element->reason = data;
	element->next_reason = *reason;
	*reason = element;
}
