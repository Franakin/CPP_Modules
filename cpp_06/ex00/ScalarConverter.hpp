/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 15:34:46 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/24 16:14:01 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	POSINF,
	NEGINF,
	NAN,
	NONE,
};

class ScalarConverter
{
	private:
		static std::string	_literal;
		static int			_i;
		static float		_f;
		static double		_d;
		static e_type		_type;

		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &copy);
		static int			getInt(void);
		static float		getFloat(void);
		static double		getDouble(void);
		static std::string	getLiteral(void);

		static bool	isInt(void);
		static bool	isChar(void);
		static bool	isFloat(void);
		static bool	isDouble(void);
		static bool	hasDecimals(std::string output);

		static void	casting(void);
		static void	printInt(void);
		static void	printChar(void);
		static void	printFloat(void);
		static void	printDouble(void);

	public:
		static void	convert(const std::string literal);
};

#endif
