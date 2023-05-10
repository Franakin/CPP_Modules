/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/06 19:33:05 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/06 19:40:49 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
private:

public:
	FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap(const std::string newName);
	~FragTrap();

	FragTrap	&operator=(const FragTrap &copy);

	void	highFivesGuys(void);
};
