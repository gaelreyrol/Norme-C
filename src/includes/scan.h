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

int		is_valid(t_file *file);
void	get_extension(t_file *file);

#endif /* !SCAN_H */
