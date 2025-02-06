/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:30:34 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/06 13:54:26 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "Default Constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	if(this != &src)
	{
		this->vec = src.vec;
		this->data = src.data;
	}
	std::cout << "Copy constructor called" << std::endl;
}

BitcoinExchange const & BitcoinExchange::operator=(BitcoinExchange const & src)
{
	if(this != &src)
	{
		this->vec = src.vec;
		this->data = src.data;
	}
	return *this;	
}


BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "Destructor called" << std::endl;
}

int BitcoinExchange::fill_data_csv(void)
{
	std::string line;
	std::ifstream input("data.csv");
	if(input.is_open() == false)
    	throw OpenFailure();
	std::string arr[2];
	int date;
	std::getline(input,line, '\n');

	while(std::getline(input,line, '\n'))
    {
		
		for(int i = 0;i < line.size();i++)
		{
			if(line[i] == ',')
			{
				arr[0] = line.substr(0,i);
				arr[1] = line.substr(i+1);
				break ;
			}
		}
		date = parse_date(arr[0]);
		if(date == 1)
			return 1;
		this->data[date] = get_value(arr[1]);
        line.clear();
    }
	for (std::map<int, float>::iterator it = this->data.begin(); it != this->data.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << "\n";
    }
	return 0;
}


int BitcoinExchange::get_from_file(std::string filename)
{
	std::string line;
	std::ifstream input(filename);
	if(input.is_open() == false)
    	throw OpenFailure();
	std::string arr[2];
	int date;
	std::getline(input,line, '\n');

	while(std::getline(input,line, '\n'))
    {
		
		for(int i = 0;i < line.size();i++)
		{
			if(line[i] == ',')
			{
				arr[0] = line.substr(0,i);
				arr[1] = line.substr(i+1);
				break ;
			}
		}
		date = parse_date(arr[0]);
		if(date == 1)
			return 1;
		this->data[date] = get_value(arr[1]);
        line.clear();
    }
	for (std::map<int, float>::iterator it = this->data.begin(); it != this->data.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << "\n";
    }
	return 0;
}