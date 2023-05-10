/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 16:04:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 16:04:30 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	virtual	~WrongAnimal();

	WrongAnimal	&operator=(const WrongAnimal &copy);

	virtual void	makeSound(void) const;
	std::string		getType(void) const;
};

#endif
