/*
**  @@ScriptName: main.h
**  @@Project: Norme-c
**
**  @@Author: Zevran<info@zevran.net>
*/

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>

void	help(void);
void	scan(char *file_name);

/*
** File Informations
*/
typedef struct 	s_file
{
	char	*name;
	char	extension;
	int		is_valid;
}				t_file;

/*
** File Content
** Lines are stored in a double chain list.
*/
typedef struct 	s_content
{
	char	*line;
	int		line_nbr;
	struct s_content *next;
	struct s_content *prev;
}				t_content;

typedef struct
{
	t_content *first;
	t_content *last;
}				t_list_content;

/*
** Errors List
** Errors are stored in a double chain list.
*/
typedef struct 	s_reason
{
	char	*reason;
	int		line_nbr;
	struct s_reason *next;
	struct s_reason *prev;
}				t_reason;

typedef struct
{
	t_reason *first;
	t_reason *last;
}				t_list_reason;

#endif /* !MAIN_H */
