/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 17:16:06 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/29 18:43:39 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
	private:
		std::string name;
	public:
		Zombie();
		~Zombie();

		void announce(void);
		void setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
