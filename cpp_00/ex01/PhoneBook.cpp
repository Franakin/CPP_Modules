/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 17:56:56 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/29 13:30:47 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addContact(int i)
{
	contact[i].setFirstName();
	contact[i].setLastName();
	contact[i].setNickname();
	contact[i].setNumber();
	contact[i].setSecret();
}

const std::string	PhoneBook::returnContent(int i, e_content cont)
{
	if (cont == FIRST)
		return (contact[i].getFirstName());
	else if (cont == LAST)
		return (contact[i].getLastName());
	else if (cont == NICK)
		return (contact[i].getNickname());
	else if (cont == NBR)
		return (contact[i].getNumber());
	else if (cont == SECRET)
		return (contact[i].getSecret());
	return ("");
}