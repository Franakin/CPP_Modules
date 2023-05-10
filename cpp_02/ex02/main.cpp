/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 18:10:21 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/05 19:19:25 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
{
Fixed const a(2), c(1234);
Fixed	b(10.56f);

std::cout << "a = " << a.toInt() << std::endl << "b = " << b.toFloat() << std::endl << "c = " << c.toInt() << std::endl << std::endl;

std::cout << "a + b = " << a + b << std::endl;
std::cout << "b - a = " << b - a << std::endl;
std::cout << "b * a + c = " << b * a + c << std::endl;
std::cout << "b / a = " << b / a << std::endl << std::endl;

std::cout << "b = " << b << std::endl;
++b;
b++;
++b;
std::cout << "b = " << b << std::endl << std::endl;

std::cout << "a > b = " << (a > b) << std::endl;
std::cout << "a < b = " << (a < b) << std::endl;
std::cout << "a >= b = " << (a >= b) << std::endl;
std::cout << "c <= c = " << (c >= c) << std::endl;
std::cout << "c == c = " << (c == c) << std::endl << std::endl;

std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
std::cout << "max(c, c) = " << Fixed::max(c, c) << std::endl << std::endl;
}
std::cout << "------ Previous exercise tests ------" << std::endl;
{
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}
atexit(f);
return 0;
}
