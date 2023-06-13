/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 19:03:08 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/13 19:03:09 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
	atexit(f);
	return 0;
}

