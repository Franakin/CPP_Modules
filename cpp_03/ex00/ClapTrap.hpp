/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 15:44:06 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/06 15:54:23 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap
{
private:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;
public:
	ClapTrap();
	ClapTrap(const ClapTrap &copy);
	ClapTrap(const std::string name);
	~ClapTrap();

	ClapTrap	&operator=(const ClapTrap &copy);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
