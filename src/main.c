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

void    scan(char *file)
{
    t_file  *norme;

    get_extension(norme, file);
    if (norme->is_valid)
    {
        ft_print_name(file);
        ft_open_file(norme, file);
        //ft_scan_file(norme, file);
    }
    else
    {
        ft_putstr(norme->reason);
        return ;
    }
}

void    help(void)
{
    ft_putstr("Usage : ");
    ft_putstr("file_name.(c/h)\n");
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
