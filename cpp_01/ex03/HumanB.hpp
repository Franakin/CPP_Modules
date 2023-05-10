/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 17:35:28 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/29 18:41:42 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB(const std::string name);
		~HumanB();

		void	attack(void);
		void	setWeapon(Weapon &weapon);
};

#endif