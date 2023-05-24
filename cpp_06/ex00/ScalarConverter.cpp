/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 15:34:43 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/24 16:28:37 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <sstream>

std::string ScalarConverter::_literal = "0";
int			ScalarConverter::_i = 0;
float		ScalarConverter::_f = 0.0f;
double		ScalarConverter::_d = 0.0;
e_type		ScalarConverter::_type = NONE;


//defaults--------------------------------------------------------------------------------------------------------------------------------------------
ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	_literal = copy.getLiteral();
	_i = copy.getInt();
	_f = copy.getFloat();
	_d = copy.getDouble();
}

ScalarConverter::~ScalarConverter(void){}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &copy)
{
	_literal = copy.getLiteral();
	_i = copy.getInt();
	_f = copy.getFloat();
	_d = copy.getDouble();
	return (*this);
}

//MEMEBER FUNCTIONS--------------------------------------------------------------------------------------------------------------------------------------------
//bools-------------------------------------------------------------------------------------------------------------------------------------------------
bool	ScalarConverter::isChar(void)
{
	return (_literal.size() == 1 && _literal.at(0) >= 0 && _literal.at(0) <= 127);
}

bool	ScalarConverter::isInt(void)
{
	return (_literal.find_first_not_of("-0123456789") == std::string::npos &&
	(_literal.find_last_of("-") == 0 || _literal.find_last_of("-") == std::string::npos));
}

bool	ScalarConverter::isFloat(void)
{
	return (_literal.find_first_not_of("-01234567890.f") == std::string::npos &&
	_literal.find_first_of("f") == _literal.size() - 1 &&
	_literal.find_first_of(".") == _literal.find_last_of(".") &&
	(_literal.find_last_of("-") == 0 || _literal.find_last_of("-") == std::string::npos));
}

bool	ScalarConverter::isDouble(void)
{
	return (_literal.find_first_not_of("-01234567890.") == std::string::npos &&
	_literal.find_first_of(".") == _literal.find_last_of(".") &&
	(_literal.find_last_of("-") == 0 || _literal.find_last_of("-") == std::string::npos));
}

bool	ScalarConverter::hasDecimals(std::string output)
{
	return (output.find_first_of('e') == std::string::npos && output.find_first_of('.') != std::string::npos);
	
}

//converter---------------------------------------------------------------------------------------------------------------------------------------------
void	ScalarConverter::convert(const std::string literal)
{
	_literal = literal;
	try
	{
		if (isInt())
		{
			_type = INT;
			_i = std::stoi(_literal);
		}
		else if (isChar())
		{
			_type = CHAR;
			_i = _literal.at(0);
		}
		else if (isFloat())
		{
			_type = FLOAT;
			_f = std::stof(_literal);
		}
		else if (isDouble())
		{
			_type = DOUBLE;
			_d = std::stod(_literal);
		}
		else if (_literal == "nan" || _literal == "nanf")
			_type = NAN;
		else if (_literal == "+inf" || _literal == "+inff")
			_type = POSINF;
		else if (_literal == "-inf" || _literal == "-inff")
			_type = NEGINF;
		else
			_type = NONE;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
	casting();
	printChar();
	printInt();
	printFloat();
	printDouble();
}

//casting----------------------------------------------------------------------------------------------------------------------------------------------
void	ScalarConverter::casting(void)
{
	switch (_type)
	{
	case INT:
	case CHAR:
		_f = static_cast <float>(_i);
		_d = static_cast <double>(_i);
		break;
	case FLOAT:
		_i = static_cast <float>(_f);
		_d = static_cast <double>(_f);
		break;
	case DOUBLE:
		_f = static_cast <float>(_d);
		_i = static_cast <double>(_d);
		break;
	default:
		break;
	}
}

//printing--------------------------------------------------------------------------------------------------------------------------------------------
void	ScalarConverter::printInt(void)
{
	std::cout << "Int: ";
	if ((_i == -2147483648 && _literal.compare(0, 11, "-2147483648")) ||
		_type == NONE ||
		_type == NAN ||
		_type == POSINF ||
		_type == NEGINF)
		std::cout << "Impossible";
	else
		std::cout << _i;
	std::cout << std::endl;
}

void	ScalarConverter::printChar(void)
{
	std::cout << "Char: ";
	if ((_i == -2147483648 && _literal.compare(0, 11, "-2147483648")) ||
		(_i < 0 || _i > 127) ||
		_type == NONE ||
		_type == NAN ||
		_type == POSINF ||
		_type == NEGINF)
		std::cout << "Impossible";
	else if (!isprint(static_cast <char>(_i)))
		std::cout << "Non displayable";
	else
		std::cout << '\'' << static_cast <char>(_i) << '\'';
	std::cout << std::endl;
}

void	ScalarConverter::printFloat(void)
{
	std::stringstream	buffer;

	std::cout << "Float: ";
	switch (_type)
	{
		case POSINF:
			std::cout << "+inff" << std::endl;
			return;
		case NEGINF:
			std::cout << "-inff" << std::endl;
			return;
		case NAN:
			std::cout << "nanf" << std::endl;
			return;
		case NONE:
			std::cout << "Impossible" << std::endl;
			return;
		default:
			buffer << _f;
			std::cout << _f;
	}
	if (buffer.str() != "inf")
	{
		if (!hasDecimals(buffer.str()))
			std::cout << ".0";
		std::cout << 'f';
	}
	std::cout << std::endl;
}

void	ScalarConverter::printDouble(void)
{
	std::stringstream	buffer;
	
	std::cout << "Double: ";
	switch (_type)
	{
		case POSINF:
			std::cout << "+inf" << std::endl;
			return;
		case NEGINF:
			std::cout << "-inf" << std::endl;
			return;
		case NAN:
			std::cout << "nan" << std::endl;
			return;
		case NONE:
			std::cout << "Impossible" << std::endl;
			return;
		default:
			buffer << _d;
			std::cout << _d;
	}
	if (!hasDecimals(buffer.str()))
		std::cout << ".0";
	std::cout << std::endl;
}
