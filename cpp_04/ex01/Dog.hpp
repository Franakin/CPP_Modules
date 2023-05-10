/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 15:43:23 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 19:57:23 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain	*brain;
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();

	Dog	&operator=(const Dog &copy);

	void		makeSound(void) const;
	void		printBrainPtr(void) const;
	void		setIdea(int i, std::string idea);
	std::string	getIdea(int i) const;
};

#endif
