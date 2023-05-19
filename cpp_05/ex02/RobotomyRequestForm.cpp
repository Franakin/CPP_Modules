/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 16:21:49 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/19 18:27:04 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <time.h>

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
RobotomyRequestForm::RobotomyRequestForm(const std::string newTarget) : AForm("RobotomyRequestForm", 72, 45), target(newTarget){}

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("N/A"){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45), target(copy.target){}

RobotomyRequestForm::~RobotomyRequestForm(void){}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	(void)copy;
	return (*this);
}

//member functions--------------------------------------------------------------------------------------------------------------------------------------------
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	const bool	success = (bool)(time(NULL) % 2);

	if (executor.getGrade() > this->getMinExecGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSignStatus())
		throw AForm::FormNotSignedForExecException();
	std::cout << "*DRILLING NOISES*" << std::endl;
	if (success)
		std::cout << this->target << " has successfully been robotomized!" << std::endl;
	else
		std::cout << this->target << " was not successfully robotomized :( better luck next time" << std::endl;
}