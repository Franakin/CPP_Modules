/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 17:54:09 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/01 19:44:21 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <queue>
#include "easyfind.hpp"

// void	f(void)
// {
// 	system("leaks -q test");
// }

int main(void)
{
	std::array<int, 5> arrayCont = {1, 2, 3, 4, 5};
	
	std::vector<int> vectorCont;
	for (int i = 0; i < 7; i++)
		vectorCont.push_back(i);

	std::deque<int> dequeCont;
	for (int i = 0; i < 7; i++)
		dequeCont.push_back(i);

	std::list<int> listCont;
	listCont.assign(1, 2);

	std::forward_list<int> forwListCont;
	forwListCont.assign(1, 2);

	std::cout << "Is there a 6 in array container? ";
	(easyfind(arrayCont, 6)) ? std::cout << "Yes" : std::cout << "No"; std::cout << std::endl;
	std::cout << "Is there a 6 in vector container? ";
	(easyfind(vectorCont, 6)) ? std::cout << "Yes" : std::cout << "No"; std::cout << std::endl;
	std::cout << "Is there a 6 in deque container? ";
	(easyfind(dequeCont, 6)) ? std::cout << "Yes" : std::cout << "No"; std::cout << std::endl;
	std::cout << "Is there a 6 in list container? ";
	(easyfind(listCont, 6)) ? std::cout << "Yes" : std::cout << "No"; std::cout << std::endl;
	std::cout << "Is there a 6 in forward_list container? ";
	(easyfind(forwListCont, 6)) ? std::cout << "Yes" : std::cout << "No"; std::cout << std::endl;

	// atexit(f);
	return 0;
}
