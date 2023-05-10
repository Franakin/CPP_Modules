/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 18:52:28 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/06 19:18:29 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap(const std::string newName);
	~ScavTrap();

	ScavTrap	&operator=(const ScavTrap &copy);

	void	attack(const std::string &target);
	void	guardGate(void);
};
