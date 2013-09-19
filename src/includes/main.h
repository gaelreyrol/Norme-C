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
void    scan(char *file_name);

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
** Lines are stored in a chain list.
*/
typedef struct 	s_content
{
	char *line;
	struct s_content *next_line;
}				t_content;

/*
** Errors List
** Errors are stored in a chain list.
*/
typedef struct 	s_reason
{
	char *reason;
	struct s_reason *next_reason;
}				t_reason;

#endif /* !MAIN_H */
