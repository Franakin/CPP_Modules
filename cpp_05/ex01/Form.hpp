/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 15:52:27 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/10 18:12:21 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			minSignGrade;
	const int			minExecGrade;
public:
	Form();
	Form(const std::string &newName, const int &signGrade, const int &execGrade);
	Form(const Form &copy);
	~Form();
	Form	&operator=(const Form &copy);

	std::string	getName(void) const;
	bool		getSignStatus(void) const;
	int			getMinSignGrade(void) const;
	int			getMinExecGrade(void) const;
	void		beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
	class FormAlreadySignedException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Form &b);

#endif
