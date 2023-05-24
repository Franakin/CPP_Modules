/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Accessors.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 17:33:39 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/24 14:49:20 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::getLiteral(void)
{
	return _literal;
}

int		ScalarConverter::getInt(void)
{
	return _i;
}

float	ScalarConverter::getFloat(void)
{
	return _f;
}

double	ScalarConverter::getDouble(void)
{
	return _d;
}