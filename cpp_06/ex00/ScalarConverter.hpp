/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 15:34:46 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/23 19:24:53 by fpurdom       ########   odam.nl         */
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
	NONE,
};

class ScalarConverter
{
	private:
		static std::string	_literal;
		static char			_c;
		static int			_i;
		static float		_f;
		static double		_d;
		static e_type		_type;

		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &copy);
		static int			getInt(void);
		static char			getChar(void);
		static float		getFloat(void);
		static double		getDouble(void);
		static std::string	getLiteral(void);

		static bool	isInt(void);
		static bool	isChar(void);
		static bool	isFloat(void);
		static bool	isDouble(void);
		static bool	hasDecimals(void);

		static void	casting(void);
		static void	printAll(void);
		static std::string	makeInt(void);
		static std::string	makeChar(void);
		static std::string	makeFloat(void);
		static std::string	makeDouble(void);

	public:
		static void	convert(const std::string literal);
};

#endif
