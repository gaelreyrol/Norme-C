/*
**  @@ScriptName: regex.c
**  @@Project: Norme-C
**
**  @@Author: Zevran<info@zevran.net>
*/

#include "includes/regex.h"

int	regex(char *request, char *regex)
{
	int err;
	int match;
	regex_t preg;

	err = regcomp(&preg, regex, REG_NOSUB | REG_EXTENDED);
	if (err != 0)
		return (1);
	match = regexec(&preg, request, 0, NULL, 0);
	regfree(&preg);
	if (match == REG_NOMATCH)
		return (2);
	return (0);
}