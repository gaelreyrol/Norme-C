/*
**  @@ScriptName: scan.h
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#ifndef SCAN_H
# define SCAN_H

# define EOL '\n'

enum e_config
{
	fnct_nbr = 5,
	fnct_max = 25,
	line_max = 80,
};

void	get_extension(t_file *norme, char *file);
int		check_line_length(t_file *norme, char *line);
void    ft_scan_file(t_file *norme, char *file);

#endif /* !SCAN_H */
