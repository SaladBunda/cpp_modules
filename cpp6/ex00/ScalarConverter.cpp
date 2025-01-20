/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:14:03 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/20 13:12:17 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	(void) src;
	return ;
}

ScalarConverter const & ScalarConverter::operator=(ScalarConverter const & src)
{
	(void) src;
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}
int	fcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *s, int *error)
{
	int					i;
	int					sign;
	long long			num;

	i = 0;
	if (fcmp(s, "-0") == 0 || fcmp(s, "+0") == 0 || fcmp(s, "0") == 0)
		return (0);
	num = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			sign = -1;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 +(s[i++] - 48);
	}
	if (s[i] != '\0' || num == 0 || (num * sign) > 2147483647 || (num * sign) < -2147483648)
		*error = 1;
	return (num * sign);
}


double testZero(std::string str)
{
	int i = 0;
	while(str[i] && str[i] == '0')
		i++;
	if(str[i] == '.')
		i++;
	
}



void ScalarConverter::convert(std::string var)
{
	if(var.find('.') != var.npos)
	{
		std::string afterpoint = var.substr(var.find('.') + 1);
		std::cout <<afterpoint << std::endl;
		if(afterpoint.find('.') != afterpoint.npos || afterpoint == "")
		{
			std::cout << "invalid number" << std::endl;
			return ;
		}
		
		std::cout << "goes to float tester" << std::endl;
		double number = atof((char *)var.c_str());
		if(afterpoint.back() == 'f')
		{
			float floatnum = static_cast<float>(number);
			int num = static_cast<int>(number);
			if(num < 33 || num > 126)
					std::cout << "char: Non Displayable" << std::endl;
			else
				std::cout << "char: " << "'"<<static_cast<char>(num) << "'" <<std::endl;
			std::cout << "int: " <<num << std::endl;
			float numf = static_cast<float>(floatnum);
			double numd = static_cast<double>(floatnum);
			std::cout << std::fixed << std::setprecision(10);
			std::cout << "float: " << numf<< "f" << std::endl;
			std::cout << "double: " << numd << std::endl;
		}
		else
		{
			int num = static_cast<int>(number);
			if(num < 33 || num > 126)
					std::cout << "char: Non Displayable" << std::endl;
			else
				std::cout << "char: " << "'"<<static_cast<char>(num) << "'" <<std::endl;
			std::cout << "int: " <<num << std::endl;
			float numf = static_cast<float>(number);
			std::cout << std::fixed << std::setprecision(10);
			std::cout << "float: " << numf<< "f" << std::endl;
			std::cout << "double: " << number << std::endl;
		}
		return ;
		
	}
	else
	{
		std::cout << "call atoi" << std::endl;
		int error = 0;
		int num = ft_atoi((char *)var.c_str(),&error);
		if(error == 1)
			std::cout << "invalid num" << std::endl;
		else
		{
			if(num < 33 || num > 126)
				std::cout << "char: Non Displayable" << std::endl;
			std::cout << "int: " <<num << std::endl;
			float numf = static_cast<float>(num);
			double numd = static_cast<double>(num);
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << numf<< "f" << std::endl;
			std::cout << "double: " << numd << std::endl;
			
		}
			
	}
	
	
}

