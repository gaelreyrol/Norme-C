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

void    scan(char *file)
{
    t_file  *norme;

    ft_open_file(norme, file);
    ft_putstr(norme->tab);
    //ft_scan_file(norme, file);
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
