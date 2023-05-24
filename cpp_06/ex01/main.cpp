/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 16:43:49 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/24 17:01:43 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

void	f(void)
{
	system("leaks -q serializer");
}

int main(void)
{
	Data		soMuchInfo;
	Data		*ptrData;
	uintptr_t	raw;

	soMuchInfo.randomAssData = "Look at all these bits";
	soMuchInfo.letsAddMore = 69;

	std::cout << std::endl << "Stuff inside Data: " << soMuchInfo.randomAssData << soMuchInfo.letsAddMore << std::endl;
	std::cout << "Pointer to Data value: " << &soMuchInfo << std::endl << std::endl;;

	raw = Serializer::serialize(&soMuchInfo);
	
	std::cout << "Raw value of Data: " << raw << std::endl << std::endl;

	ptrData = Serializer::deserialize(raw);
	
	std::cout << "Stuff inside Data after serialization: " << ptrData->randomAssData << ptrData->letsAddMore << std::endl;
	std::cout << "Pointer to Data after serialization value: " << ptrData << std::endl << std::endl;
	atexit(f);
	return 0;
}
