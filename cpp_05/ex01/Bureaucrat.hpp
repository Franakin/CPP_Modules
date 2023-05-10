/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:04:57 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/10 18:16:16 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &newName, int newGrade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();
	Bureaucrat		&operator=(const Bureaucrat &copy);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);
	void		signForm(Form &form);

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
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b);

#endif
