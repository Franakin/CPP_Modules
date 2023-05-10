/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 15:33:31 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 19:52:06 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
	Brain	*brain;
public:
	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat	&operator=(const Cat &copy);

	void		makeSound(void) const;
	void		printBrainPtr(void) const;
	void		setIdea(int i, std::string idea);
	std::string	getIdea(int i) const;
};

#endif
