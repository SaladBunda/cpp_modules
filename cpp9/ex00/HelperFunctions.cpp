/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:34:27 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/04 20:52:36 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int parse_date(std::string date)
{
	std::string arr[3];
	int j = 0;
	for(int i =0; i < date.size();i++)
	{
		if(date[i] == '-')
		{
			arr[j] = date.substr(i,j - i + 1);
			j++;
			i++;
		}
		if(j > 3)
			break;
	}
	for(int i = 0;i < 3;i++)
		std::cout << arr[i] <<std::endl;
	return 1;
}

int convert_date(std::string date)
{
	return 1;
}