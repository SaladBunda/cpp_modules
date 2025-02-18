/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:20:00 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/18 21:22:11 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int TestArguments(std::string str, std::vector<std::string> vec)
{
	if(str.find_first_not_of("0123456789") != str.npos)
	{
		std::cout << "Found forbidden shit" << std::endl;
		return 1;
	}
	else
	{
		for(std::vector<std::string>::iterator it = vec.begin();it!=vec.end();it++)
		{
			if(*it == str)
			{
				std::cout << "duplicate" << std::endl;
				return 1;
			}
		}
	}
	return 0;		
}

std::string intToString(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}

std::string giveLabel(int i)
{
	int pairNumber = (i / 2) + 1;
	if(i % 2 ==0)
		return ("b" + intToString(pairNumber));
	else
		return("a" +  intToString(pairNumber));
}

