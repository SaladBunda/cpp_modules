/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:34:27 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/05 20:40:10 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isLeapYear(int year) {
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

int test_date_string(std::string date)
{
	int count = 0;
	for(int i = 0;i < date.size();i++)
	{
		if(date[i] != '-' && (date[i]  < '0' || date[i] >'9'))
			return 1;
	}
	for(int i = 0;i < date.size();i++)
	{
		if(date[i] == '-')
			count++;
	}
	if(count != 2)
		return 1;
	return 0;
}

int test_array(std::string arr[])
{
	int m_d[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if(arr[0].size() != 4 || arr[1].size() > 2 || arr[2].size() > 2)
		return 1;
	std::cout << arr[0] << " " << arr[1] << " " << arr[2] << std::endl;
	std::cout << atoi(arr[0].c_str()) <<  atoi(arr[1].c_str()) << atoi(arr[2].c_str()) << std::endl;
	if(atoi(arr[1].c_str()) <= 12 && atoi(arr[1].c_str()) >= 1)
	{
		if(atoi(arr[1].c_str()) == 2 && isLeapYear(atoi(arr[0].c_str())) == 1)
		{
			if(atoi(arr[2].c_str()) > 29 || atoi(arr[2].c_str()) < 1)
				return 1;
		}
		else if(atoi(arr[2].c_str()) > m_d[atoi(arr[1].c_str()) - 1] || atoi(arr[2].c_str()) < 1)
		{
			std::cout << m_d[atoi(arr[1].c_str()) - 1] << std::endl;
			return 1;
		}
	}
	else
		return 1;

	return 0;
}

int parse_date(std::string date)
{
	std::string arr[3];
	if(test_date_string(date) == 1)
	{
		std::cout << "Invalid string" << std::endl;
		return 1;
	}
	int j = 0;
	int k = 0;
	int i = 0;
	std::cout << date.size() << " date size\n";
	for(i =0; i < date.size();i++)
	{
		std::cout << "i: " << i << std::endl;
		if(date[i] == '-')
		{
			std::cout << "here\n";
			arr[j] = date.substr(k,i - k);
			j++;
			i++;
			k = i;
		}
	}
	arr[j] = date.substr(k,i - k + 1);
	std::cout << i - k + 1 << "test" << std::endl;
	j++;
	i++;
	k = i;
	if(test_array(arr) == 1)
	{
		std::cout << "test array failed" << std::endl;
		return 1;
	}
	for(int i = 0;i < 3;i++)
		std::cout << i << " " <<arr[i] <<std::endl;
	return 0;
}

// int convert_date(std::string date)
// {
// 	return 1;
// }

int parse_line(std::string line)
{
	
}