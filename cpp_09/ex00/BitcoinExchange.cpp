/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 14:40:18 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/06/26 18:36:15 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <algorithm>

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
BitcoinExchange::BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){(void)copy;}

BitcoinExchange::~BitcoinExchange(void){}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy){(void)copy; return (*this);}

//static fnctions--------------------------------------------------------------------------------------------------------------------------------------
static bool	isInt(std::string &str)
{
	if (*(std::prev(str.end())) == ' ')
		str.erase(std::prev(str.end()));
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		if ((!std::isdigit(*it) && *it != '-'))
			return false;
	return true;
}

static bool	isFloat(std::string &str)
{
	const bool	oneDot = std::count(str.begin(), str.end(), '.') <= 1;

	if (!oneDot)
		return false;
	if (*(str.begin()) == ' ')
		str.erase(str.begin());
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		if ((!std::isdigit(*it) && *it != '.'))
			return false;
	return true;
}

static void	initDate(std::string &date, std::string &nbrStr, int &year, int &month, int &day, float &number)
{
	const size_t	firstDash = date.find_first_of('-');
	const size_t	lastDash = date.find_last_of('-');
	try
	{
		year = std::stoi(date.substr(0, firstDash));
		month = std::stoi(date.substr(firstDash + 1, lastDash - firstDash - 1));
		day = std::stoi(date.substr(lastDash + 1, std::string::npos));
		number = std::stof(nbrStr);
	}
	catch(const std::invalid_argument& e)
	{
		throw std::runtime_error("Error: Invalid argument: " + date + '|' + nbrStr);
	}
	catch(const std::out_of_range& e)
	{
		throw std::runtime_error("Error: Out of range: " + date + '|' + nbrStr);
	}
}

static bool	validDate(int &year, int &month, int &day)
{
	return (year <= 0 || month <= 0 || day <= 0 || month > 12 || day > 31 ||
			(day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day > 29 && month == 2) ||
			(day > 28 && month == 2 && (year % 4 || (!(year % 100) && year % 400))));
}

//member functions-------------------------------------------------------------------------------------------------------------------------------------
void	BitcoinExchange::readPriceFile(std::string priceFileName)
{
	std::ifstream	fin(priceFileName);
	if (!fin)
		throw std::runtime_error("Error: Unable to find or open file: " + priceFileName);

	std::string	date, priceStr;
	int			i = 1, year, month, day;
	float		price;

	try
	{
		std::getline(fin, date);
		if (date != "date,exchange_rate")
			throw std::exception();
		while (std::getline(fin, date, ','))
		{
			i++;
			std::getline(fin, priceStr);
			if (std::count(date.begin(), date.end(), '-') != 2 || date.find(' ') != std::string::npos || priceStr.find(' ') != std::string::npos || !isInt(date) || !isFloat(priceStr))
				throw std::exception();
			initDate(date, priceStr, year, month, day, price);
			if (price < 0 || validDate(year, month, day))
 				throw std::exception();
			priceData[year][month][day] = price;
		}
	}
	catch(const std::exception& e)
	{
		throw std::runtime_error("Error: Wrong input in data.csv on line " + std::to_string(i) + ": \"" + date + ((i != 1) ? "," + priceStr + '\"' : "\" (Incorrect format indicator)"));
	}
}

void	BitcoinExchange::exec(std::string valFileName)
{
	std::ifstream	fin(valFileName);
	if (!fin)
		throw std::runtime_error("Error: Unable to find or open file: " + valFileName);

	std::string	line, date, valStr;
	int			year, month, day;
	float		value;

	std::getline(fin, line);
	if (line != "date | value" && line != "date|value" && line != "date |value" && line != "date| value")
		throw std::runtime_error("Error: First line must be a correct format indicator");
	while (std::getline(fin, line))
	{
		try
		{
			if (line.find('|') == std::string::npos)
				throw std::runtime_error("Error: Incomplete: \"" + line + '\"');
			const size_t	splitSpot = line.find('|');
			date = line.substr(0, splitSpot);
			if (std::count(date.begin(), date.end(), '-') != 2)
				throw std::runtime_error("Error: Unknown date format: \"" + date + '\"');
			valStr = line.substr(splitSpot + 1, std::string::npos);
			if (!isInt(date) || !isFloat(valStr))
				throw std::runtime_error("Error: Uknown characters or format: \"" + line + '\"');
			initDate(date, valStr, year, month, day, value);
			if (validDate(year, month, day))
				throw std::runtime_error("Error: Invalid date: " + date);
			if (value < 0 || value > 1000)
				throw std::runtime_error("Error: Invalid value (not between 0 and 1000): " + valStr);
			if (year < 2009 || (year == 2009 && month == 1 && day == 1))
				throw std::runtime_error("Error: Bitcoin didn't exist on " + date);
			while (priceData.find(year) == priceData.end())
			{
				month = 12;
				day = 31;
				year--;
			}
			while (priceData[year].find(month) == priceData[year].end())
			{
				if (month == 1)
					{
						month = 12;
						year--;
					}
					else
						month--;
			}
			while (priceData[year][month].find(day) == priceData[year][month].end())
			{
				if (day == 1)
				{
					day = 31;
					if (month == 1)
					{
						month = 12;
						year--;
					}
					else
						month--;
				}
				else
					day--;
			}
			std::cout << date << " => " << priceData[year][month][day] * value << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}