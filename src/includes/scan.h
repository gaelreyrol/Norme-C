/*
**  @@ScriptName: scan.h
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#ifndef SCAN_H
# define SCAN_H

# include <string.h>

enum e_config
{
	fnct_nbr 	= 5,
	fnct_max 	= 25,
	line_max 	= 80,
	head_height = 11
};

# define BAD_FILE "Bad extension file\n"
# define LINE_LEN "Line larger than 80 characters\n"
# define CORUPT_H "Corrupted header line (must begin by '/*' and finish by '*/')\n"

int		is_valid(t_file *file);
void	get_extension(t_file *file, t_list_reason *r);

int		check_integrity_header(t_list_content *t, t_content *content, t_list_reason *r);

void	scan_file_type(t_file *file, t_list_content *t, t_list_reason *r, char type);
void	scan_c_file(t_file *file, t_list_content *t, t_list_reason *r);
void	scan_h_file(t_file *file, t_list_content *t, t_list_reason *r);

#endif /* !SCAN_H */
