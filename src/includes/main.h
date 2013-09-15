/*
**  @@ScriptName: main.h
**  @@Project: Norme-c
**
**  @@Author: Zevran<info@zevran.net>
*/

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>

void    help(void);
void    scan(char *file);

typedef struct  s_file
{
    char    *tab;
    int     is_valid;
    char	extension;
    char    *reason;
}               t_file;

#endif /* !MAIN_H */
