/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 15:51:37 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 16:23:07 by fpurdom       ########   odam.nl         */
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
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound(); //dog
	meta->makeSound(); //unkown
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;

	const WrongCat kitty;
	std::cout << kitty.getType() << " " << std::endl;
	kitty.makeSound(); //wrong cat sound
	
	atexit(f);
	return 0;
}

