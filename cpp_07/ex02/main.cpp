/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 17:54:09 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/31 19:13:09 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

void	f(void)
{
	system("leaks -q test");
}

int main(void)
{
    try
    {
		std::cout << "\n\033[1;46m--INT ARRAY--\033[0m\n" << std::endl;
        Array<int>  arr(10);
        for (int i = 0; i < 10; i++)
            arr[i] = i;
        std::cout << "Array contents: " << arr << std::endl;
        std::cout << "On wrong access: " << arr[-10] << std::endl;;
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;;
    }

    try
    {
		std::cout << "\n\033[1;46m--CHAR ARRAY--\033[0m\n" << std::endl;
        Array<char>  arr(10);
        for (int i = 0; i < 10; i++)
            arr[i] = i + 'a';
        std::cout << "Array contents: " << arr << std::endl;
        std::cout << "On wrong access: " << arr[10] << std::endl;;
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;;
    }

    try
    {
		std::cout << "\n\033[1;46m--FLOAT ARRAY--\033[0m\n" << std::endl;
        Array<float>  arr(10);
        for (int i = 0; i < 10; i++)
            arr[i] = i + 0.69;
        std::cout << "Array contents: " << arr << std::endl;
        std::cout << "On wrong access: " << arr[2147483647] << std::endl;;
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;;
    }

    try
    {
		std::cout << "\n\033[1;46m--EMPTY ARRAY--\033[0m\n" << std::endl;
        Array<int>  arr;
        std::cout << "Array contents: " << arr << std::endl;
        std::cout << "On wrong access: " << arr[0] << std::endl;;
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;;
    }

    try
    {
		std::cout << "\n\033[1;46m--COPY ARRAY--\033[0m\n" << std::endl;
        Array<int>  arr(10);
        for (int i = 0; i < 10; i++)
            arr[i] = i;
        Array<int> newArr(2);
        newArr = arr;
        std::cout << "Old array contents: " << arr << std::endl;
        std::cout << "New array contents (should be the same): " << newArr << std::endl;
        Array<int>  arrayThree(newArr);
        std::cout << "Construction through copy: " << arrayThree << std::endl;
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;;
    }
    std::cout << std::endl;
	atexit(f);
	return 0;
}
