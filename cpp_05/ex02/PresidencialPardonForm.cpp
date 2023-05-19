/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidencialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 16:21:42 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/19 18:25:03 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidencialPardonForm.hpp"

//defaults---------------------------------------------------------------------------------------------------------------------------------------------------
PresidencialPardonForm::PresidencialPardonForm(const std::string newTarget) : AForm("PresidencialPardonForm", 25, 5), target(newTarget){}

PresidencialPardonForm::PresidencialPardonForm(void) : AForm("PresidencialPardonForm", 25, 5), target("N/A"){}

PresidencialPardonForm::PresidencialPardonForm(const PresidencialPardonForm &copy) : AForm("PresidencialPardonForm", 25, 5), target(copy.target){}

PresidencialPardonForm::~PresidencialPardonForm(void){}

//operators---------------------------------------------------------------------------------------------------------------------------------------------------
PresidencialPardonForm	&PresidencialPardonForm::operator=(const PresidencialPardonForm &copy)
{
	(void)copy;
	return (*this);
}

//member functions---------------------------------------------------------------------------------------------------------------------------------------------------
void	PresidencialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getMinExecGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSignStatus())
		throw AForm::FormNotSignedForExecException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}