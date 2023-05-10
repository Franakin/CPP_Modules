/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 13:46:35 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/29 14:25:12 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	makeCollum(std::string str)
{
	unsigned long		i = 0;
	unsigned long		spaces = 10;
	const unsigned long	str_len = str.length();

	if (str_len < 10)
	{
		while (str_len < spaces)
			{
				std::cout << ' ';
				spaces--;
			}
		std::cout << str + '|';
	}
	else if (str_len > 10)
	{
		spaces = 9;
		while (spaces > i)
		{
			std::cout << str[i];
			i++;
		}
		std::cout << ".|";
	}
	else
		std::cout << str + '|';
}

static void	displayTable(PhoneBook *phonebook)
{
	int	i = 0;

	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (i < 8 && !phonebook->returnContent(i, PhoneBook::FIRST).empty())
	{
		std::cout << "|         " << i + 1 << '|';
		makeCollum(phonebook->returnContent(i,PhoneBook:: FIRST));
		makeCollum(phonebook->returnContent(i, PhoneBook::LAST));
		makeCollum(phonebook->returnContent(i, PhoneBook::NICK));
		std::cout << std::endl;
		i++;
	}
}

static void	searchContacts(PhoneBook *phonebook)
{
	int			n;
	std::string	command;

	if (phonebook->returnContent(0, PhoneBook::FIRST).empty())
	{
		std::cout << "Try adding some contacts first" << std::endl;
		return;
	}
	displayTable(phonebook);
	std::cout << "Enter contact index: ";
	std::getline(std::cin, command);
	if (std::cin.eof())
		exit (0);
	if (command == "1" || command == "2" || command == "3" || command == "4" || command == "5" || command == "6" || command == "7" || command == "8")
	{
		n = stoi(command) - 1;
		if (!phonebook->returnContent(n, PhoneBook::FIRST).empty())
		{
			std::cout << "First name: " << phonebook->returnContent(n, PhoneBook::FIRST) << std::endl;
			std::cout << "Last name: " << phonebook->returnContent(n, PhoneBook::LAST) << std::endl;
			std::cout << "Nickname: " << phonebook->returnContent(n, PhoneBook::NICK) << std::endl;
			std::cout << "Phone number: " << phonebook->returnContent(n, PhoneBook::NBR) << std::endl;
			std::cout << "Darkest secret: " << phonebook->returnContent(n, PhoneBook::SECRET) << std::endl;
		}
		else
			std::cout << "Seems like that contact is empty" << std::endl;
	}
	else
		std::cout << "That ain't a valid index silly (1 - 8)" << std::endl;
}

int	main(void)
{
	int			i = 0;
	std::string	command;
	PhoneBook	phonebook;

	while (true)
	{
		std::cout << std::endl << "Enter command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (0);
		if (command == "EXIT")
			return (0);
		else if (command == "ADD")
		{
			phonebook.addContact(i);
			i = (i + 1) % 8;
		}
		else if (command == "SEARCH")
			searchContacts(&phonebook);
		else
			std::cout << "Command not found :c" << std::endl;
	}
}
