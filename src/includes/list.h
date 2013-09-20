/*
**  @@ScriptName: list.h
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#ifndef LIST_H

# define LIST_H

# include <stdlib.h>

void	add_line_list(t_content **content, char *data);
void	add_reason_list(t_reason **reason, char *data);
void	clear_reason_list(t_reason **reason);
void	clear_content_list(t_content **content);
void	view_reason_list(void *list);

#endif /* !LIST_H */
