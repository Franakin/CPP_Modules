SRC = main.cpp\
PmergeMe.cpp\
DequeUtils.cpp\
VectorUtils.cpp\

NAME = PmergeMe

$(NAME)	:	$(SRC)
	c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $(NAME) -Ofast

all		:	$(NAME)

clean	:
	rm -f $(NAME)

fclean	:
	rm -f $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re

