/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 16:21:30 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/29 18:51:45 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		~Weapon();

		const std::string	getType(void);
		void				setType(const std::string);
};

#endif