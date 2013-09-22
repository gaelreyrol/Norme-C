/*
**  @@ScriptName: main.c
**  @@Project: Norme-c
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/main.h"
#include "includes/filedesc.h"
#include "includes/scan.h"
#include "includes/tools.h"
#include "includes/regex.h"
#include "includes/list.h"

void    scan(char *file_name)
{
    t_file  *file;
    t_list_content *t = malloc(sizeof(t_list_content));
    t_reason *reason = NULL;

    file->name = file_name;
    init_content_list(t);
    get_extension(file, &reason);
    if (file->is_valid)
    {
        init_content_list(t);
        if (ft_open_file(file, t))
        {
            ft_print_name(file->name);
            view_content_list(t);
        }
    }
    else
    {
        view_reason_list(file, reason);
        clear_reason_list(&reason);
        return ;
    }
}

void    help(void)
{
    ft_putstr("Usage : file_name.(c/h)\n");
}

int main(int argc, char **argv)
{
    int i;
    
    i = 1;
    if (argc == 1)
        help();
    else
    {
        while (i < argc)
        {
            scan(argv[i]);
            i++;
        }
    }
    return (0);
}
