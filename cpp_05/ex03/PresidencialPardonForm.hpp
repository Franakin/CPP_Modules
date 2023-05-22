/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidencialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 16:21:46 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/19 16:14:53 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENCIALPARDONFORM_HPP
#define PRESIDENCIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidencialPardonForm : public AForm
{
private:
	const std::string	target;
public:
	PresidencialPardonForm();
	PresidencialPardonForm(const std::string newTarget);
	PresidencialPardonForm(const PresidencialPardonForm &copy);
	~PresidencialPardonForm();

	PresidencialPardonForm	&operator=(const PresidencialPardonForm &copy);

	void	execute(const Bureaucrat &executor) const;
};

#endif
