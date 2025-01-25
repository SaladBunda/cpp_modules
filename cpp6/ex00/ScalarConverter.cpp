/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:14:03 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/25 10:54:31 by ael-maaz         ###   ########.fr       */
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


int is_num(std::string var)
{
	int i = 0;
	while(var[i])
	{
		if(var[i] < '0' || var[i] > '9')
			return 1;
		i++;
	}
	return 0;
}

int	ft_atoi(const char *s, int *error)
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
	if ((s[i] != '\0' && num == 0) || s[i] != '\0' || (num * sign) > 2147483647 || (num * sign) < -2147483648)
		*error = 1;
	return (num * sign);
}

int pretest(std::string var)
{
	if(var == "nan" || var == "+inf" || var == "-inf")
	{
		std::cout << "char: impossible\nint: impossible" << std::endl;
		std::cout << "float: " << var + "f"<< std::endl;
		std::cout << "double: " << var<< std::endl;
		return 0;
	}
	else if(var == "nanf" || var == "+inff" || var == "-inff")
	{
		std::cout << "char: impossible\nint: impossible" << std::endl;
		std::cout << "float: " << var<< std::endl;
		std::cout << "double: " << var.substr(0,var.length() - 1) << std::endl;
		return 0;
	}
	else
		return 1;
}

int test_side(std::string var)
{
	int end;
	int start = var.find('.') + 1;
	int error = 0;

	if(var.back() == 'f')
		end = var.length()- var.find('.') - 2;
	else
		end = var.length()- var.find('.') - 1;
	std::string first = var.substr(0,var.find('.'));
	std::string seconds = var.substr(start,end);

	ft_atoi(first.c_str(), &error);
	if(is_num(seconds) == 1)
		return 1;
	ft_atoi((char*) seconds.c_str(), &error);
	if(error == 1)
	{
		std::cout << "ko" << std::endl;
		return 1;
	}
	std::cout << "ok" << std::endl;
	return 0;
}


void ScalarConverter::convert(std::string var)
{
	if(pretest(var) == 0)
		return ;
	if(var.find('.') != var.npos)//if there is a dot present in the string
	{
		if(test_side(var) == 1)
		{
			std::cout << "invalid number" << std::endl;
			return ;
		}
		std::string afterpoint = var.substr(var.find('.') + 1);
		std::cout <<afterpoint << std::endl;
		if(afterpoint.find('.') != afterpoint.npos || afterpoint == "")
		{
			std::cout << "invalid number" << std::endl;
			return ;
		}
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
			std::cout << "float: " << numf << "f" << std::endl;
			std::cout << "double: " << numd << std::endl;
			
		}
			
	}
	
	
}

