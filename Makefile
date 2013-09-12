#
#  @@ScriptName: Makefile
#  @@Project: Norme-C
#
#  @@Author: Zevran<info@zevran.net>
#

NAME = norme
GCC = gcc -Wall -Werror -Wextra
DEBUG = clang -Wall -Werror -Wextra -ggdb
LIBRARIES = includes
SRC = src/
RM = /bin/rm

all:
	@$(GCC) -I $(LIBRARIES) -o $(NAME) $(SRC)*.c

debug: 
	@$(DEBUG) -I $(LIBRARIES) -o $(NAME) $(SRC)*.c

clean:
	@$(RM) -r norme.SYM

fclean:
	@$(RM) -f $(NAME)

re: clean fclean all

.PHONY: debug clean fclean re