/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:50:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/06 16:59:28 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>


class OpenFailure : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Failed to Open Input file");
		}
};


class InvalidValue : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Invalid value for price");
		}
};

class BitcoinExchange
{
	public:
		std::map<int,float> data;
		std::map<int,float> vec;
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange();
		BitcoinExchange const & operator=(BitcoinExchange const & src);
		int fill_data_csv(void);
		int get_from_file(std::string filename);
		
		
	
};

// int convert_date(std::string date);

int parse_date(std::string date);

int transform_date(std::string arr[]);

float get_value(std::string value);

std::string trim(std::string str);


#endif