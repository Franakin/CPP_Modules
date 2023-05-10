/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 15:25:38 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 15:56:52 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(const Animal &copy);
	virtual	~Animal();

	Animal	&operator=(const Animal &copy);

	virtual void	makeSound(void) const;
	std::string		getType(void) const;
};

#endif
