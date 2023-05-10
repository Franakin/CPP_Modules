/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 15:51:37 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 20:07:03 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
	//AAnimal	wontWork;
	std::cout << std::endl << "----- Constructor and destructor messages -----" << std::endl << std::endl;
	const AAnimal	*zoo[] = {new Cat(), new Cat(), new Dog(), new Dog(), NULL};
	std::cout << std::endl;
	int i =0;
	while (zoo[i])
	{
		delete zoo[i];
		i++;
	}

	std::cout << std::endl << "----- Deep copy proving -----" << std::endl << std::endl;
	std::cout << "//Create a cat and print its brain pointer" << std::endl;
	Cat	*cat1 = new Cat();
	cat1->printBrainPtr();

	std::cout << std::endl << "//Create another cat using copy constructor and print its brain pointer" << std::endl;
	Cat cat2(*cat1);
	cat2.printBrainPtr();

	std::cout << std::endl << "//Create new default cat, use the assingment operator and print its new brain pointer" << std::endl;
	Cat cat3;
	cat3 = *cat1;
	cat3.printBrainPtr();

	std::cout << std::endl << "//Set the first idea of each cats brain to something different, then print them" << std::endl;
	cat1->setIdea(0, "I am CAT NUMBER ONE!");
	cat2.setIdea(0, "Wait, you're one? That means I must be two!");
	cat3.setIdea(0, "You guys are getting paid??");
	std::cout << cat1->getIdea(0) << std::endl;
	std::cout << cat2.getIdea(0) << std::endl;
	std::cout << cat3.getIdea(0) << std::endl;
	std::cout << std::endl;

	delete cat1;
	atexit(f);
	return 0;
}

