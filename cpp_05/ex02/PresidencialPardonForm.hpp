/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidencialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/16 16:21:46 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/16 16:21:47 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENCIALPARDONFORM_HPP
#define PRESIDENCIALPARDONFORM_HPP

#include <iostream>

class PresidencialPardonForm
{
private:

public:
	PresidencialPardonForm();
	PresidencialPardonForm(const PresidencialPardonForm &copy);
	~PresidencialPardonForm();

	PresidencialPardonForm	&operator=(const PresidencialPardonForm &copy);
};

#endif
