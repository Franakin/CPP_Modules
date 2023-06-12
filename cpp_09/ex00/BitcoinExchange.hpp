/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 14:40:20 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/12 15:49:55 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<int, std::map<int, std::map<int, float> > >	priceData;

		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange	&operator=(const BitcoinExchange &copy);


	public:
		BitcoinExchange();
		~BitcoinExchange();

		void	readPriceFile(std::string priceFileName);
		void	exec(std::string valFileName);
};

#endif
