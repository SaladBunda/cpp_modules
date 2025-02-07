/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:33:39 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/07 20:34:15 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int TestArgChar(std::string arg)
{
	size_t result = arg.find_first_not_of("0123456789+-/* "); 
	if(result == arg.npos)
		return 0;
	else
	{
		std::cerr << "Found forbidden characters" << std::endl;
		return 1;
	}
}


int PerformOperation(std::string opd1,std::string opd2, std::string op)
{
	if(op == "+")
		return std::atoi(opd1.c_str()) + std::atoi(opd2.c_str());
	if(op == "-")
		return std::atoi(opd1.c_str()) - std::atoi(opd2.c_str());
	if(op == "*")
		return std::atoi(opd1.c_str()) * std::atoi(opd2.c_str());
	if(op == "/")
	{
		if(opd2 == "0")
			throw DivisionByZeroException();
		else
			return std::atoi(opd1.c_str()) / std::atoi(opd2.c_str());
	}
	return 0;
}