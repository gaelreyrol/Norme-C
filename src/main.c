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

void    scan(char *file_name)
{
    t_file  *file;
    t_content *content;
    t_reason *reason;

    file->name = file_name;

    get_extension(file);
    if (norme->is_valid)
    {
        if (ft_open_file(file))
            ft_print_name(file->name);
        //ft_scan_file(norme, file);
    }
    else
    {
        ft_putstr("norme: ");
        ft_putstr(file->name);
        ft_putstr(": ");
        ft_print_color(norme->reason, RED);
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
