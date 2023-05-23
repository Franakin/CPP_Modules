/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 15:34:43 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/23 19:32:09 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::_literal = "0";
char		ScalarConverter::_c = '\0';
int			ScalarConverter::_i = 0;
float		ScalarConverter::_f = 0.0f;
double		ScalarConverter::_d = 0.0;
e_type		ScalarConverter::_type = NONE;


//defaults--------------------------------------------------------------------------------------------------------------------------------------------
ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	_literal = copy.getLiteral();
	_c = copy.getChar();
	_i = copy.getInt();
	_f = copy.getFloat();
	_d = copy.getDouble();
}

ScalarConverter::~ScalarConverter(void){}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &copy)
{
	_literal = copy.getLiteral();
	_c = copy.getChar();
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

bool	ScalarConverter::hasDecimals(void)
{
	const size_t	lastNonZero = _literal.find_last_not_of("0f");
	const size_t	firstDot = _literal.find_first_of('.');

	return (lastNonZero > firstDot && lastNonZero - firstDot < 5);
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
			_c = _literal.at(0);
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
		else
			_type = NONE;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
	casting();
	printAll();
}

//casting----------------------------------------------------------------------------------------------------------------------------------------------
void	ScalarConverter::casting(void)
{
	switch (_type)
	{
	case CHAR:
		_i = static_cast <int>(_c);
		_f = static_cast <float>(_c);
		_d = static_cast <double>(_c);
	case INT:
		_c = static_cast <char>(_i);
		_f = static_cast <float>(_i);
		_d = static_cast <double>(_i);
		break;
	case FLOAT:
		_c = static_cast <char>(_f);
		_i = static_cast <float>(_f);
		_d = static_cast <double>(_f);
		break;
	case DOUBLE:
		_c = static_cast <char>(_d);
		_f = static_cast <float>(_d);
		_i = static_cast <double>(_d);
		break;
	case NONE:
		break;
	}
}

//printing--------------------------------------------------------------------------------------------------------------------------------------------
void	ScalarConverter::printAll(void)
{
	if (_type != NONE)
	{
		std::cout << "Char: " << makeChar() << std::endl;
		std::cout << "Int: " << makeInt() << std::endl;
		std::cout << "Float: " << makeFloat() << std::endl;
		std::cout << "Double: " << makeDouble() << std::endl;
	}
	else
	{
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible"<< std::endl;
		std::cout << "Float: Impossible" << std::endl;
		std::cout << "Double: Impossible" << std::endl;
	}
}

std::string	ScalarConverter::makeInt(void)
{
	if (_i == -2147483648 && _literal != "-2147483648")
		return "Impossible";
	return std::to_string(_i);
}

std::string	ScalarConverter::makeChar(void)
{
	if (_i == -2147483648 && _literal != "-2147483648")
		return "Impossible";
	if (_c < 0 || _c > 127)
		return "Impossible";
	else if (!isprint(_c))
		return "Non displayable";
	return std::string() + '\'' + _c + '\'';
}

std::string	ScalarConverter::makeFloat(void)
{
	std::string	strFloat = std::to_string(_f);
	int	i = strFloat.size() - 1;

	while (strFloat.at(i) == '0' && strFloat.at(i - 1) != '.')
		i--;
	strFloat.erase(i + 1, std::string::npos);
	strFloat.append("f");
	return strFloat;
}

std::string	ScalarConverter::makeDouble(void)
{
	std::string	strDouble = std::to_string(_d);
	int	i = strDouble.size() - 1;

	while (strDouble.at(i) == '0' && strDouble.at(i - 1) != '.')
		i--;
	strDouble.erase(i + 1, std::string::npos);
	return strDouble;
}
