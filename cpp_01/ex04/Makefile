SRC = main.cpp\
Sed.cpp\

NAME = sed

$(NAME)	:	$(SRC)
	c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $(NAME)

all		:	$(NAME)

clean	:
	rm -f $(NAME)

fclean	:
	rm -f $(NAME)

re		:	fclean all
