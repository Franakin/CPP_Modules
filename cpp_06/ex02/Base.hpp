/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 17:13:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/24 17:24:42 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
	public:
		virtual ~Base();
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
