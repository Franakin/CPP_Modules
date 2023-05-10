/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sed.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 13:02:23 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/04 15:57:31 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Sed
{
private:
	std::string	inFile;
	std::string outFile;
public:
	Sed(std::string fileName);
	~Sed();

	void	replace(const std::string toFind, const std::string replaceWith);
};
