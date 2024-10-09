NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 

SRC = philosop.c \
	ft_check_arg.c \
	utils.c \
	ft_split.c \

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "\033[1m \e[32m Ready to PHILOSOPHERS \033[0m"

clean:
	@rm -rf $(SRC:.c=.o)
	@echo "\033[1m \e[32m OBJ deleted \033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1m \e[32m $(NAME) deleted \033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
