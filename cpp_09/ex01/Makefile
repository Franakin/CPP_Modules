SRC = main.cpp\
RPN.cpp\

NAME = RPN

$(NAME)	:	$(SRC)
	c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $(NAME) -Ofast -fsanitize=undefined

all		:	$(NAME)

clean	:
	rm -f $(NAME)

fclean	:
	rm -f $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re
