/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 15:13:50 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/13 17:41:44 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
RPN::RPN(void){}

RPN::RPN(std::string newInput) : input(newInput){}

RPN::RPN(const RPN &copy){(void)copy;}

RPN::~RPN(void){}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
RPN	&RPN::operator=(const RPN &copy){(void)copy; return (*this);}

//static functions--------------------------------------------------------------------------------------------------------------------------------------------
static bool	isNbr(std::string &token)
{
	if (std::isdigit(*token.begin()))
		return true;
	return false;
}

static bool	isOper(std::string &token)
{
	const std::string::const_iterator	it = token.begin();

	if (*it == PLUS || *it == MINUS || *it == MULTI || *it == DIVI)
		return true;
	return false;
}

//member functions--------------------------------------------------------------------------------------------------------------------------------------------
void	RPN::calc(e_operator op)
{
	const long	nbr2 = (long)numbers.top();
	numbers.pop();
	const long	nbr1 = (long)numbers.top();
	numbers.pop();
	long		result;

	switch (op)
	{
		case PLUS:
			result = nbr1 + nbr2;
			break;
		case MINUS:
			result = nbr1 - nbr2;
			break;
		case MULTI:
			result = nbr1 * nbr2;
			break;
		case DIVI:
			if (nbr2 == 0)
				throw std::runtime_error("Trying to devide by 0");
			result = nbr1 / nbr2;
	}
	if (result > 2147483647 || result < -2147483648)
		throw std::runtime_error("Out of bounds");
	numbers.push((int)result);
}

void	RPN::exec(void)
{
	std::stringstream	ss(input);
	std::string			token;

	if (input.length() == 0 || input.find_first_not_of(' ') == std::string::npos)
		throw std::runtime_error("Nothing to calculate");
	while (std::getline(ss, token, ' '))
	{
		if (token.length() != 0)
		{
			if (token.length() > 1)
				throw std::runtime_error("Token has more than 1 character");
			if (isNbr(token))
				numbers.push(std::stoi(token));
			else if (isOper(token))
				if (numbers.size() > 1)
					calc((e_operator)*token.begin());
				else
					throw std::runtime_error("Incorrect order or missing numbers");
			else
				throw std::runtime_error("Unknown character: " + token);
		}
	}
	if (numbers.size() != 1)
		throw std::runtime_error("Not enough operators for calculation");
	std::cout << numbers.top() << std::endl;
}