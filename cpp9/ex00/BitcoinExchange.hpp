/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:50:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/04 20:53:25 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>


class BitcoinExchange
{
	public:
		std::map<int,float> data;
		std::map<int,float> vec;
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange();
		BitcoinExchange const & operator=(BitcoinExchange const & src);
		int fill_data(void);
		
		
	
};

int convert_date(std::string date);

int parse_date(std::string date);


#endif