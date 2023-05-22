/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 15:34:40 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/22 15:34:41 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
	atexit(f);
	return 0;
}

