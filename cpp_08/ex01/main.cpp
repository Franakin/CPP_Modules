/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 15:10:59 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/03 14:53:38 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "Span.hpp"

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
	std::cout << "\n\033[1;46m--TEST #1--\033[0m\n" << std::endl;
	try
	{
		Span sp = Span(5);

		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);
		sp.addNumber(40);
		sp.addNumber(50);
		
		std::cout << "Contents: " << sp << std::endl;
		std::cout << "Min span: " << sp.shortestSpan() << std::endl;
		std::cout << "Max span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n\033[1;46m--TEST #2--\033[0m\n" << std::endl;
	try
	{
		Span sp = Span(100000);
		std::list<int>	bigList;
		bigList.assign(100000, 1);

		sp.addNumbers(bigList.begin(), bigList.end());
		
		std::cout << "Contents: " << sp << std::endl;
		std::cout << "Min span: " << sp.shortestSpan() << std::endl;
		std::cout << "Max span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n\033[1;46m--TEST #3--\033[0m\n" << std::endl;
	try
	{
		Span sp = Span(100000);
		std::list<int>	bigList;
		for (int i = 0; i < 100000; i++)
			bigList.insert(bigList.end(), i);

		sp.addNumbers(bigList.begin(), bigList.end());
		
		std::cout << "Contents: " << sp << std::endl;
		std::cout << "Min span: " << sp.shortestSpan() << std::endl;
		std::cout << "Max span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\033[1;46m--TEST #4 (Max span)--\033[0m\n" << std::endl;
	try
	{
		Span sp = Span(10);

		sp.addNumber(INT_MAX);
		sp.addNumber(INT_MIN);
		
		std::cout << "Contents: " << sp << std::endl;
		std::cout << "Min span: " << sp.shortestSpan() << std::endl;
		std::cout << "Max span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\033[1;46m--SUBJECT TEST--\033[0m\n" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "Contents: " << sp << std::endl;
		std::cout << "Min span: " << sp.shortestSpan() << std::endl;
		std::cout << "Max span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\033[1;46m--EXCEPTION #1--\033[0m\n" << std::endl;
	try
	{
		Span sp = Span(4);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "Contents: " << sp << std::endl;
		std::cout << "Min span: " << sp.shortestSpan() << std::endl;
		std::cout << "Max span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n\033[1;46m--EXCEPTION #1 (but using range of iterators to fill)--\033[0m\n" << std::endl;
	try
	{
		Span sp = Span(69);
		std::list<int>	bigList;
		for (int i = 0; i < 100000; i++)
			bigList.insert(bigList.end(), i);

		sp.addNumbers(bigList.begin(), bigList.end());
		
		std::cout << "Contents: " << sp << std::endl;
		std::cout << "Min span: " << sp.shortestSpan() << std::endl;
		std::cout << "Max span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n\033[1;46m--EXCEPTION #2--\033[0m\n" << std::endl;
	try
	{
		Span sp = Span(10000000);
		sp.addNumber(420);
		
		std::cout << "Contents: " << sp << std::endl;
		std::cout << "Min span: " << sp.shortestSpan() << std::endl;
		std::cout << "Max span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	atexit(f);
	return 0;
}
