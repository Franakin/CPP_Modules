/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sed.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 13:02:35 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/04 15:58:24 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <fstream>

Sed::Sed(std::string fileName)
{
	this->inFile = fileName;
	this->outFile = fileName + ".replace";
}

Sed::~Sed()
{
}

void	Sed::replace(const std::string toFind, const std::string replaceWith)
{
	std::ifstream	input(this->inFile);
	if (!input.is_open())
	{
		std::cout << "File opening error" << std::endl;
		exit (EXIT_FAILURE);
	}
	std::string		line;
	if (!std::getline(input, line, '\0'))
	{
		std::cout << "Empty file" << std::endl;
		exit (EXIT_FAILURE);
	}
	std::ofstream	output(this->outFile);
	const size_t	findLen = toFind.length();
	for (size_t i = line.find(toFind); i != std::string::npos; i = line.find(toFind))
	{
		line.erase(i, findLen);
		line.insert(i, replaceWith);
	}
	input.close();
	output << line;
	output.close();
}
