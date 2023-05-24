/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 17:22:20 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/24 18:34:47 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <unistd.h>

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
	std::cout << "Generating random class 1/5" << std::endl;
	Base	*a = generate();
	usleep(90000);
	std::cout << "Generating random class 2/5" << std::endl;
	Base	*b = generate();
	usleep(90000);
	std::cout << "Generating random class 3/5" << std::endl;
	Base	*c = generate();
	usleep(90000);
	std::cout << "Generating random class 4/5" << std::endl;
	Base	*d = generate();
	usleep(90000);
	std::cout << "Generating random class 5/5" << std::endl;
	Base	*e = generate();

	std::cout << "\na = ";
	identify(a);
	std::cout << "a = ";
	identify(*a);

	std::cout << "\nb = ";
	identify(b);
	std::cout << "b = ";
	identify(*b);

	std::cout << "\nc = ";
	identify(c);
	std::cout << "c = ";
	identify(*c);

	std::cout << "\nd = ";
	identify(d);
	std::cout << "d = ";
	identify(*d);

	std::cout << "\ne = ";
	identify(e);
	std::cout << "e = ";
	identify(*e);

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;

	Base	*ptr = new Base;
	Base	&ref = *ptr;
	std::cout << "\nBase only pointer = ";
	identify(ptr);
	std::cout << "\nBase only reference = ";
	identify(ref);

	delete ptr;
	std::cout << std::endl;
	atexit(f);
	return 0;
}
