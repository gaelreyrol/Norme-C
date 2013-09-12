/*
**  @@ScriptName: main.c
**  @@Project: Norme-c
**
**  @@Author: Zevran<info@zevran.net>
*/

#include <stdio.h>

#include "filedesc.h"
#include "scan.h"
#include "main.h"

void    scan(char *file)
{
    t_file  *norme = NULL;

    ft_open_file(norme, file);
    ft_scan_file(norme, file);
}

void    help(void)
{
    printf("Usage : ");
    printf("file_name.(c/h)\n");
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