/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 15:52:27 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/16 14:41:26 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int			minSignGrade;
	const int			minExecGrade;
public:
	AForm();
	AForm(const std::string &newName, const int &signGrade, const int &execGrade);
	AForm(const AForm &copy);
	virtual ~AForm();
	AForm	&operator=(const AForm &copy);

	std::string	getName(void) const;
	bool		getSignStatus(void) const;
	int			getMinSignGrade(void) const;
	int			getMinExecGrade(void) const;
	void		beSigned(const Bureaucrat &b);

	virtual void	execute(const Bureaucrat &executor) const = 0;

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
	class FormNotSignedForExecException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const AForm &b);

#endif
