/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 15:25:38 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 20:03:13 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string	type;
public:
	AAnimal();
	AAnimal(const AAnimal &copy);
	virtual	~AAnimal();

	AAnimal	&operator=(const AAnimal &copy);

	virtual void	makeSound(void) const = 0;
	std::string		getType(void) const;
};

#endif
