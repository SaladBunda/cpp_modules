/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:30:34 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/04 18:54:41 by ael-maaz         ###   ########.fr       */
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

int BitcoinExchange::fill_data(void)
{
	

	return 0;
}