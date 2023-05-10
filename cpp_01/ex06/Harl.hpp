/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 15:22:10 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/04 15:45:18 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>	

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	typedef	void	(Harl::*funcPtr)(void);

public:
	Harl(void);
	~Harl(void);

	void	complain(std::string level);
};