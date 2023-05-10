/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 18:05:26 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/07 19:49:33 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string	ideas[100];
public:
	Brain();
	Brain(const Brain &copy);
	~Brain();

	Brain	&operator=(const Brain &copy);

	
	void		setIdea(int i, std::string idea);
	std::string	getIdea(int i) const;
};

#endif
