/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 11:25:35 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/04 12:41:58 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
	std::cout << "\n\033[1;46m--REGULAR ITERATORS--\033[0m\n" << std::endl;
	{
		MutantStack<int> 			mStack;
		MutantStack<int>::iterator	it1, it2;

		mStack.push(1);
		mStack.push(2);
		mStack.push(3);
		mStack.push(4);
		mStack.push(5);
		mStack.push(6);
		
		it1 = mStack.begin();
		it2 = mStack.end();

		it2--;
		std::cout << "//MutantStack\nStart: " << *it1 << "\nEnd: " << *it2 << std::endl;

		std::list<int> 				list;
		std::list<int>::iterator	it3, it4;

		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(4);
		list.push_back(5);
		list.push_back(6);
		
		it3 = list.begin();
		it4 = list.end();

		it4--;
		std::cout << "\n//List\nStart: " << *it3 << "\nEnd: " << *it4 << std::endl;
	}
	std::cout << std::endl;
	atexit(f);
	return 0;
}

