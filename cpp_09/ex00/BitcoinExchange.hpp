/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 14:40:20 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/09 16:13:03 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

enum e_dataType {PRICEDATA, QUANTDATA};

class BitcoinExchange
{
	private:
		std::map<std::string, std::string>	priceData;
		std::map<std::string, std::string>	quantData;

		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange	&operator=(const BitcoinExchange &copy);


	public:
		std::map<std::string, std::string>	&getData(e_dataType data); //for testing
		BitcoinExchange();
		~BitcoinExchange();

		void	readFile(std::string inFileName, e_dataType data);
		void	checkPriceData(void);
		void	calcAndPrintValue(std::map<std::string, std::string> &it);
};

#endif
