/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 12:37:23 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/29 14:29:36 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	number;
	std::string	secret;
	
public:
	void				setFirstName(void);
	const std::string	getFirstName(void);
	void				setLastName(void);
	const std::string	getLastName(void);
	void				setNickname(void);
	const std::string	getNickname(void);
	void				setNumber(void);
	const std::string	getNumber(void);
	void				setSecret(void);
	const std::string	getSecret(void);
};

#endif
