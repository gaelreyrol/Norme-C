/*
**  @@ScriptName: list.h
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#ifndef LIST_H

# define LIST_H

# include <stdlib.h>

void	init_content_list(t_list_content *t);

void	add_line_list(t_list_content *t, char *data, int line_nbr);
void	add_reason_list(t_reason **reason, char *data, int line_nbr);

void	view_reason_list(t_file *file, t_reason *reason);
void	view_content_list(t_list_content *t);

void	clear_reason_list(t_reason **reason);
void	clear_content_list(t_list_content *t);

#endif /* !LIST_H */
