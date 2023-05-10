/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 17:59:49 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/05 18:38:59 by fpurdom       ########   odam.nl         */
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
	Fixed	operator+(const Fixed &n) const;
	Fixed	operator-(const Fixed &n) const;
	Fixed	operator*(const Fixed &n) const;
	Fixed	operator/(const Fixed &n) const;

	Fixed	&operator++(void);
	Fixed	operator++(int i);
	Fixed	&operator--(void);
	Fixed	operator--(int i);

	bool	operator>(const Fixed &n) const;
	bool	operator<(const Fixed &n) const;
	bool	operator>=(const Fixed &n) const;
	bool	operator<=(const Fixed &n) const;
	bool	operator==(const Fixed &n) const;
	bool	operator!=(const Fixed &n) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	
	static Fixed		&min(Fixed &n1, Fixed &n2);
	static const Fixed	&min(const Fixed &n1, const Fixed &n2);
	static Fixed		&max(Fixed &n1, Fixed &n2);
	static const Fixed	&max(const Fixed &n1, const Fixed &n2);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &n);