SRC = Zombie.cpp\
	main.cpp\
	newZombie.cpp\
	randomChump.cpp\

NAME = zombies

$(NAME)	:	$(SRC)
	c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $(NAME)

all		:	$(NAME)

clean	:
	rm -f $(NAME)

fclean	:
	rm -f $(NAME)

re		:	fclean all
