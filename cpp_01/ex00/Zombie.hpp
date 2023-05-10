/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/04 14:16:27 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/28 17:38:31 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
	private:
		std::string name;
	public:
		Zombie(std::string const newName);
		~Zombie();
		void announce(void);
};

Zombie	*newZombie(std::string const name);
void 	randomChump(std::string name);

#endif
