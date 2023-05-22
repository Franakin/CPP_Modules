/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 16:21:52 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/19 15:37:59 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string	target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string newTarget);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);

	void	execute(const Bureaucrat &executor) const;
};

#endif
