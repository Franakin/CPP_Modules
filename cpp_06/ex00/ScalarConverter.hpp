/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 15:34:46 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/22 19:37:26 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

enum e_type {
	INT,
	FLOAT,
	DOUBLE,
	NONE,
};

class ScalarConverter
{
	private:
		std::string	literal;
		char		c;
		int			i;
		float		f;
		double		d;
		e_type		type;
		bool		impossible = false;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		
		ScalarConverter	&operator=(const ScalarConverter &copy);

		void		setLiteral(std::string literal);
		std::string	getLiteral(void) const;
		void		setChar(char c);
		char		getChar(void) const;
		void		setInt(int i);
		int			getInt(void) const;
		void		setFloat(float f);
		float		getFloat(void) const;
		void		setDouble(double d);
		double		getDouble(void) const;

		bool	isInt(void);
		bool	isFloat(void);
		bool	isDouble(void);

		void	convert(std::string literal);
		void	casting(void);
};

#endif
