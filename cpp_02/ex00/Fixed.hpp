/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 17:59:49 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/04/05 13:12:48 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
private:
	int 				number;
	static const int	frac = 8;

public:
	Fixed();
	Fixed(const Fixed &copy);
	~Fixed();
	Fixed	&operator=(const Fixed &copy);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};