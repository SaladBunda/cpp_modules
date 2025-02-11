/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:20:00 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/11 22:14:47 by ael-maaz         ###   ########.fr       */
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