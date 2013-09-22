/*
**  @@ScriptName: filedesc.h
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#ifndef FILEDESC_H
# define FILEDESC_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

int		ft_open_file(t_file *file, t_list_content *t);
void	print_errno(char *file_name);

#endif /* !FILEDESC_H */
