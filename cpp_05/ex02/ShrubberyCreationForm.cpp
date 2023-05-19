/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 16:21:51 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/19 14:38:51 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
ShrubberyCreationForm::ShrubberyCreationForm(const std::string newTarget) : AForm("ShrubberyCreationForm", 145, 137), target(newTarget){}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("N/A"){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 145, 137), target(copy.target){}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	(void)copy;
	return (*this);
}

//member functions--------------------------------------------------------------------------------------------------------------------------------------------
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getMinExecGrade())
		throw AForm::GradeTooLowException();
	if (!this->getSignStatus())
		throw AForm::FormNotSignedForExecException();
	std::ofstream	newFile(this->target + "_shrubbery");
	newFile << "               ,@@@@@@@,\n"
			<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
			<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
			<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88\'\n"
			<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888\'\n"
			<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88\'\n"
			<< "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
			<< "       |o|        | |         | |\n"
			<< "       |.|        | |         | |\n"
			<< "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
}