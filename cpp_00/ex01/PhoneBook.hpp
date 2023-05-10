/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 12:38:41 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/29 13:28:28 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"


class PhoneBook
{
private:
	Contact contact[8];
	
public:
	enum e_content
	{
		FIRST,
		LAST,
		NICK,
		NBR,
		SECRET
	};
	void				addContact(int i);
	const std::string	returnContent(int i, e_content cont);
};

#endif
