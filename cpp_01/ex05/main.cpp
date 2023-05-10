/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 12:52:15 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/04 16:03:52 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl MrHarl;

	MrHarl.complain("WARNING");
	MrHarl.complain("DEBUG");
	MrHarl.complain("DEBUG");
	MrHarl.complain("INFO");
	MrHarl.complain("WARNING");
	MrHarl.complain("DEBUG");
	MrHarl.complain("DEBUG");
	MrHarl.complain("INFO");
	MrHarl.complain("it's not doing a thing");
	MrHarl.complain("");
	MrHarl.complain("ERROR");
}