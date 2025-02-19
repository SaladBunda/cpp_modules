/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:30:34 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/19 22:23:15 by ael-maaz         ###   ########.fr       */
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
		
		for(unsigned int i = 0;i < line.size();i++)
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
		this->data[date] = get_value(arr[1], 0);
        line.clear();
    }
	// for (std::map<int, float>::iterator it = this->data.begin(); it != this->data.end(); ++it) {
    //     std::cout << "Key: " << it->first << ", Value: " << it->second << "\n";
    // }
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

	int pipe_count;
	while(std::getline(input,line, '\n'))
    {
		pipe_count = 0;
		
		for(unsigned int i = 0;i < line.size();i++)
		{
			if(line[i] == '|')
			{
				pipe_count++;
				arr[0] = line.substr(0,i);
				arr[1] = line.substr(i+1);
				break ;
			}
		}
		if(pipe_count != 1)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		arr[0] = trim(arr[0]);
		arr[1] = trim(arr[1]);
		date = parse_date(arr[0]);
		if(date == 1)
		{
			std::cout << "date Error: bad input => " << arr[0] << std::endl;
		}
		else
		{
			if(get_value(arr[1], 1) == -1)
			{
				continue;
			}
			std::map<int,float>::iterator it = this->data.lower_bound(date);
			
			if (it == this->data.begin())
			{
				std::cout << "No smaller key found.\n";
			}
			else if (it != this->data.end() && it->first == date)
			{
    			std::cout << arr[0] << " => " << arr[1] << " = " << it->second * get_value(arr[1], 1) << std::endl;
			} 	
			else
			{
				--it;  
				std::cout << arr[0] << " => " <<arr[1] << " = " << /* this->data[date] */ it->second * get_value(arr[1], 1) << std::endl;
			}			
		} 
        line.clear();
    }
	// for (std::map<int, float>::iterator it = this->data.begin(); it != this->data.end(); ++it) {
    //     std::cout << "Key: " << it->first << ", Value: " << it->second << "\n";
    // }
	return 0;
}