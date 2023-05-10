/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 16:24:53 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/29 18:41:33 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		HumanA(const std::string name, Weapon &weapon);
		~HumanA();
		
		void	attack(void);
		void	setWeapon(Weapon &weapon);
};

#endif