/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 17:51:50 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/29 14:30:15 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

void	Contact::setFirstName(void)
{
	while (true)
	{
		std::cout << "First name: ";
		std::getline(std::cin, firstName);
		if (std::cin.eof())
			exit (0);
		if (firstName != "")
			return;
		std::cout << "Field cannot be empty" << std::endl;
	}
}

const std::string	Contact::getFirstName(void)
{
	return (firstName);
}

void	Contact::setLastName(void)
{
	while (true)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			exit (0);
		if (lastName != "")
			return;
		std::cout << "Field cannot be empty" << std::endl;
	}
}

const std::string	Contact::getLastName(void)
{
	return (lastName);
}

void	Contact::setNickname(void)
{
	while (true)
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			exit (0);
		if (nickname != "")
			return;
		std::cout << "Field cannot be empty" << std::endl;
	}
}

const std::string	Contact::getNickname(void)
{
	return (nickname);
}

void	Contact::setNumber(void)
{
	while (true)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, number);
		if (std::cin.eof())
			exit (0);
		if (number != "")
			return;
		std::cout << "Field cannot be empty" << std::endl;
	}
}

const std::string	Contact::getNumber(void)
{
	return (number);
}

void	Contact::setSecret(void)
{
	while (true)
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, secret);
		if (std::cin.eof())
			exit (0);
		if (secret != "")
			return;
		std::cout << "Field cannot be empty" << std::endl;
	}
}

const std::string	Contact::getSecret(void)
{
	return (secret);
}