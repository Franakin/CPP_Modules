/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Functions.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 17:22:56 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/24 18:37:24 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <fstream>

Base	*generate(void)
{
	std::ifstream	devRandom("/dev/random");
	std::string		line;
	std::getline(devRandom, line);
	devRandom.close();
		
	const unsigned int	random = line.size() % 3;

	switch (random)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Unknown";
	std::cout << std::endl;
}

void	identify(Base &p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
		}
	catch (std::exception &e){}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
		}
	catch (std::exception &e){}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
		}
	catch (std::exception &e){}
	std::cout << "Unknown" << std::endl;
}
