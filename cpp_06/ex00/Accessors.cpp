/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Accessors.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 17:33:39 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/22 17:51:48 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::setLiteral(std::string literal)
{
	this->literal = literal;
}

std::string	ScalarConverter::getLiteral(void) const
{
	return this->literal;
}

void	ScalarConverter::setChar(char c)
{
	this->c = c;
}

char	ScalarConverter::getChar(void) const
{
	return this->c;
}
void	ScalarConverter::setInt(int i)
{
	this->i = i;
}

int		ScalarConverter::getInt(void) const
{
	return this->i;
}

void	ScalarConverter::setFloat(float f)
{
	this->f = f;
}

float	ScalarConverter::getFloat(void) const
{
	return this->f;
}

void	ScalarConverter::setDouble(double d)
{
	this->d = d;
}

double	ScalarConverter::getDouble(void) const
{
	return this->d;
}