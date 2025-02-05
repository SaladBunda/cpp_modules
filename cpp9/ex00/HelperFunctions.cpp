/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:34:27 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/05 13:56:54 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int test_date_string(std::string date)
{
	for(int i = 0;i < date.size();i++)
	{
		if(date[i] != '-' || (date[i]  < '0' || date[i] >'9'))
			return 1;
	}
	return 0;
}

int parse_date(std::string date)
{
	std::string arr[3];
	int j = 0;
	int k = 0;
	for(int i =0; i < date.size();i++)
	{
		if(date[i] == '-')
		{
			arr[j] = date.substr(k,i - k);
			j++;
			i++;
			k = i;
		}
		else if(i == date.size() - 1)
		{
			arr[j] = date.substr(k,i - k + 1);
			j++;
			i++;
			k = i;
		}
		if(j > 3)
			break;
	}
	for(int i = 0;i < 3;i++)
		std::cout << i << " " <<arr[i] <<std::endl;
	return 1;
}

int convert_date(std::string date)
{
	return 1;
}