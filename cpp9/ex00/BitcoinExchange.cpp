/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:30:34 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/05 20:38:51 by ael-maaz         ###   ########.fr       */
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
	while(std::getline(input,line, '\0'))
    {
        // pos = line.find(av[2]);
        // while(pos != std::string::npos)
        // {
        //     pos = line.find(av[2]);
        //     if(pos == std::string::npos)
        //         break;
        //     line.erase(pos,to_find.length());
        //     line.insert(pos, av[3]);
        
        // out << line;
        line.clear();
    }

	return 0;
}