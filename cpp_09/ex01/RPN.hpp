/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 15:13:55 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/13 16:28:47 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

enum e_operator
{
	PLUS = '+',
	MINUS = '-',
	MULTI = '*',
	DIVI = '/'
};

class RPN
{
	private:
		std::stack<int>	numbers;
		std::string		input;

		RPN();
		RPN(const RPN &copy);
		RPN	&operator=(const RPN &copy);
	public:
		RPN(std::string input);
		~RPN();
		void	exec();
		void	calc(e_operator op);
};

#endif
