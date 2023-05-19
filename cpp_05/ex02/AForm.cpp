/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 15:52:25 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/10 18:55:34 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
AForm::AForm() : name("N/A"), isSigned(false), minSignGrade(1), minExecGrade(1){}

AForm::AForm(const std::string &newName, const int &signGrade, const int &execGrade) : name(newName), isSigned(false), minSignGrade(signGrade), minExecGrade(execGrade)
{
	if (this->minSignGrade < 1 || this->minExecGrade < 1)
		throw GradeTooHighException();
	if (this->minSignGrade > 150 || this->minExecGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : name(copy.name), isSigned(copy.isSigned), minSignGrade(copy.minSignGrade), minExecGrade(copy.minExecGrade){}

AForm::~AForm(void){}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
AForm	&AForm::operator=(const AForm &copy)
{
	this->isSigned = copy.getSignStatus();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const AForm &b)
{
	out << "_____________________________\n";
	out << "| AForm name: " << b.getName() << "\n|\n";
	out << "| Min grade for signing: " << b.getMinSignGrade() << '\n';
	out << "| Min grade for executing: " << b.getMinExecGrade() << "\n|\n";
	out << "| Signed? ";
	if (b.getSignStatus())
		out << "true";
	else
		out << "false";
	out << "\n_____________________________";
	return out;
}

//member functions--------------------------------------------------------------------------------------------------------------------------------------------
std::string	AForm::getName() const
{
	return this->name;
}

bool	AForm::getSignStatus() const
{
	return this->isSigned;
}

int	AForm::getMinSignGrade() const
{
	return this->minSignGrade;
}

int AForm::getMinExecGrade() const
{
	return this->minExecGrade;
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->minSignGrade)
		throw GradeTooLowException();
	if (this->getSignStatus())
		throw FormAlreadySignedException();
	this->isSigned = true;
}

//exceptions--------------------------------------------------------------------------------------------------------------------------------------------
const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char	*AForm::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

const char	*AForm::FormNotSignedForExecException::what() const throw()
{
	return "Form needs to be signed to be executed";
}

const char	*AForm::UnluckyException::what() const throw()
{
	return "You got unlucky, better luck next time!";
}