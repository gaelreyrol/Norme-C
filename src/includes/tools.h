/*
**  @@ScriptName: tools.h
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#ifndef TOOLS_H
# define TOOLS_H

# include <unistd.h>
# include <limits.h>

# define NRM  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

void	ft_print_color(char *str, char *color);
void	ft_print_name(char *name);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

#endif /* !TOOLS_H */
