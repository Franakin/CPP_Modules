/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 14:40:18 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/09 19:46:18 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
BitcoinExchange::BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){(void)copy;}

BitcoinExchange::~BitcoinExchange(void){}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy){(void)copy; return (*this);}

//member functions-------------------------------------------------------------------------------------------------------------------------------------
std::map<std::string, std::string>	&BitcoinExchange::getData(e_dataType data) //for testing
{
	switch (data)
	{
	case PRICEDATA:
		return priceData;
	case QUANTDATA:
		return quantData;
	}
}

void	BitcoinExchange::readFile(std::string inFileName, e_dataType data)
{
	std::ifstream	fin(inFileName);
	if (!fin)
		throw std::runtime_error("Unable to find or open file: " + inFileName);
	std::string	date, number;
	std::map<std::string, std::string> *outData;
	char	deli;

	switch (data)
	{
		case PRICEDATA:
			deli = ',';
			outData = &priceData;
			std::getline(fin, date);
			break;
		case QUANTDATA:
			deli = '|';
			outData = &quantData;
	}
	while (std::getline(fin, date, deli))
	{
		std::getline(fin, number);
		(*outData)[date] = number;
	}
}

void	BitcoinExchange::checkPriceData(void)
{
	std::string	yearStr, monthStr, dayStr;
	int			yearInt, monthInt, dayInt, i = 1;
	float		price;

	try
	{
		for (std::map<std::string, std::string>::iterator it = priceData.begin(); it != priceData.end(); ++it)
		{
			const size_t	firstDash = it->first.find_first_of('-');
			const size_t	lastDash = it->first.find_last_of('-');
			
			if (firstDash == std::string::npos || lastDash == firstDash)
				throw std::runtime_error(it->first);
			yearStr = it->first.substr(0, firstDash);
			monthStr = it->first.substr(firstDash + 1, lastDash - firstDash - 1);
			dayStr = it->first.substr(lastDash + 1, std::string::npos);
			yearInt = std::stoi(yearStr);
			monthInt = std::stoi(monthStr);
			dayInt = std::stoi(dayStr);
			price = std::stof(it->second);
			if (yearInt < 0 || monthInt < 0 || monthInt > 12 || dayInt > 31 || (dayInt == 31 && (monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11)) || (dayInt > 28 && monthInt == 2 && (yearInt % 4 || (!(yearInt % 100) && yearInt % 400))) || (dayInt > 29 && monthInt == 2))
				throw std::runtime_error(it->first);
			i++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: Bad data input on line " << i << ": " << e.what() << std::endl;
		exit(1);
	}
}

void	BitcoinExchange::calcAndPrintValue(std::map<std::string, std::string> &it)
{
	(void)it;
}