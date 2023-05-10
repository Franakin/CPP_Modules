/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 17:59:49 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/05 14:04:42 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

class Fixed
{
private:
	int 				number;
	static const int	frac = 8;

public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int i);
	Fixed(const float f);
	~Fixed();

	Fixed	&operator=(const Fixed &copy);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &n);