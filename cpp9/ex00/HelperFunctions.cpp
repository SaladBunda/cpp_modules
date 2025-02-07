/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:34:27 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/07 16:42:16 by ael-maaz         ###   ########.fr       */
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
	// std::cout << arr[0] << " " << arr[1] << " " << arr[2] << std::endl;
	// std::cout << atoi(arr[0].c_str()) <<  atoi(arr[1].c_str()) << atoi(arr[2].c_str()) << std::endl;
	if(atoi(arr[1].c_str()) <= 12 && atoi(arr[1].c_str()) >= 1)
	{
		if(atoi(arr[1].c_str()) == 2 && isLeapYear(atoi(arr[0].c_str())) == 1)
		{
			if(atoi(arr[2].c_str()) > 29 || atoi(arr[2].c_str()) < 1)
				return 1;
		}
		else if(atoi(arr[2].c_str()) > m_d[atoi(arr[1].c_str()) - 1] || atoi(arr[2].c_str()) < 1)
		{
			// std::cout << m_d[atoi(arr[1].c_str()) - 1] << std::endl;
			return 1;
		}
	}
	else
		return 1;

	return 0;
}


int transform_date(std::string arr[])
{
	int num = atoi(arr[0].c_str());
	// std::cout << num << std::endl;
	num = num * 100 + atoi(arr[1].c_str());
	// std::cout << num << std::endl;
	num =  num * 100 + atoi(arr[2].c_str());
	// std::cout << num << std::endl;
	return num;
}

int parse_date(std::string date)
{
	std::string arr[3];
	int j = 0;
	int k = 0;
	int i = 0;
	if(test_date_string(date) == 1)
		return (std::cout << "Invalid string" << std::endl,1);
	for(i =0; i < date.size();i++)
	{
		if(date[i] == '-')
		{
			arr[j++] = date.substr(k,i - k);
			i++;
			k = i;
		}
	}
	arr[j] = date.substr(k,i - k + 1);
	if(test_array(arr) == 1)
	{
		std::cout << "test array failed" << std::endl;
		return 1;
	}
	return transform_date(arr);;
}


float get_value(std::string value, int option)
{
	double num = atof(value.c_str());
	if(option == 1)
	{
		if(num > 1000)
		{
			std::cout  << "Error: value too big"<< std::endl;
			return -1;
		}
	}
	if(num<0)
	{
		std::cout  << "Error: value cant be negative" << std::endl;
		return -1;
	}
	if(num > 2147483647)
	{
		std::cout  << "Error: value too big"<< std::endl;
		return -1;
	}
	return num;
}


std::string trim(std::string str)
{
    str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
    str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
    return str;
}

// int convert_date(std::string date)
// {
// 	return 1;
// }

// int parse_line(std::string line)
// {
	
// }

// std::string parse_line()
// {
	
// }