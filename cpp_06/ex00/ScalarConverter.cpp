/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 15:34:43 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/22 19:38:30 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
ScalarConverter::ScalarConverter(void) :
	literal("0"),
	c('\0'),
	i(0),
	f(0.0f),
	d(0.0){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) :
	literal(copy.literal),
	c(copy.c),
	i(copy.i),
	f(copy.f),
	d(copy.d){}

ScalarConverter::~ScalarConverter(void){}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &copy)
{
	this->literal = copy.getLiteral();
	this->c = copy.getChar();
	this->i = copy.getInt();
	this->f = copy.getFloat();
	this->d = copy.getDouble();
	return (*this);
}

//member functions--------------------------------------------------------------------------------------------------------------------------------------------
bool	ScalarConverter::isInt(void)
{
	return (this->literal.find_first_not_of("-0123456789") == std::string::npos &&
	(this->literal.find_last_of("-") == 0 || this->literal.find_last_of("-") == std::string::npos));
}

bool	ScalarConverter::isFloat(void)
{
	return (this->literal.find_first_not_of("-01234567890.f") == std::string::npos &&
	this->literal.find_first_of("f") == this->literal.length() &&
	this->literal.find_first_of(".") == this->literal.find_last_of("."));
}

bool	ScalarConverter::isDouble(void)
{
	return (this->literal.find_first_not_of("-01234567890.") == std::string::npos &&
	this->literal.find_first_of(".") == this->literal.find_last_of("."));
}

void	ScalarConverter::convert(std::string literal)
{
	this->literal = literal;
	if (isInt())
	{
		this->type = INT;
		this->i = std::stoi(this->literal);
	}
	else if (isFloat())
	{
		this->type = FLOAT;
		this->f = std::stof(this->literal);
	}
	else if (isDouble())
	{
		this->type = DOUBLE;
		this->d = std::stod(this->literal);
	}
	else
		this->type = NONE;
	casting();
}

void	ScalarConverter::casting(void)
{
	switch (this->type)
	{
	case INT:
		this->c = static_cast <char>(this->i);
		this->f = static_cast <float>(this->i);
		this->d = static_cast <double>(this->i);
		break;
	case FLOAT:
		this->c = static_cast <char>(this->f);
		this->i = static_cast <float>(this->f);
		this->d = static_cast <double>(this->f);
		break;
	case DOUBLE:
		this->c = static_cast <char>(this->d);
		this->f = static_cast <float>(this->d);
		this->i = static_cast <double>(this->d);
		break;
	case NONE:
		this->impossible = true;
	}
}