/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Accessors.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 17:33:39 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/23 15:23:04 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::getLiteral(void)
{
	return _literal;
}

char	ScalarConverter::getChar(void)
{
	return _c;
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