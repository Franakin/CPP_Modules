SRC = main.cpp\
Bureaucrat.cpp\
AForm.cpp\
ShrubberyCreationForm.cpp\
RobotomyRequestForm.cpp\
PresidencialPardonForm.cpp\
Intern.cpp\

NAME = test

$(NAME)	:	$(SRC)
	c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $(NAME)

all		:	$(NAME)

clean	:
	rm -f $(NAME)

fclean	:
	rm -f $(NAME)

re		:	fclean all

