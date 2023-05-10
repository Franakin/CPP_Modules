/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 15:43:23 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 16:17:36 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();

	Dog	&operator=(const Dog &copy);

	void	makeSound(void) const;
};

#endif
