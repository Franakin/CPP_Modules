SRC = main.cpp\
Cat.cpp\
Dog.cpp\
Animal.cpp\
WrongAnimal.cpp\
WrongCat.cpp\
Brain.cpp\

NAME = test

$(NAME)	:	$(SRC)
	c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $(NAME)

all		:	$(NAME)

clean	:
	rm -f $(NAME)

fclean	:
	rm -f $(NAME)

re		:	fclean all

