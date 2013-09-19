/*
**  @@ScriptName: filedesc.h
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#ifndef FILEDESC_H
# define FILEDESC_H

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

int		ft_open_file(t_file *file);
void	print_errno(char *file_name);

#endif /* !FILEDESC_H */
