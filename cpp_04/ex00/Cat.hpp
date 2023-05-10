/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 15:33:31 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 16:17:48 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef CAT_HPP
#define CAT_HPP

class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat	&operator=(const Cat &copy);

	void	makeSound(void) const;
};

#endif
