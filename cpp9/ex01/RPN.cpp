/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:17:40 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/07 20:37:39 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	std::cout << "Default Constructor called" << std::endl;
}

RPN::RPN(RPN const & src)
{
	if(this != &src)
	{
		this->stk = src.stk;
	}
	std::cout << "Copy constructor called" << std::endl;
}

RPN const & RPN::operator=(RPN const & src)
{
	if(this != &src)
	{
		this->stk = src.stk;
	}
	return *this;	
}

RPN::~RPN(void)
{
	std::cout << "Destructor called" << std::endl;
}

int RPN::ParseArg(std::string arg)
{
	if(TestArgChar(arg) == 1)
		return 1;

	std::stringstream s(arg);
	std::string word;
	
	// int count = 0;
    while (s >> word)
	{
        // count++;
		std::cout << word << std::endl;
		// std::cout << word<< std::endl;
		if(word.size() > 1)
		{
			std::cout << "Invalid number" << std::endl;
			return 1;
		}
		this->stk.push(word);
		if(word.find_first_of("+-/*") != arg.npos)
		{
			// std::cout << "Top: " << this->stk.top() << std::endl;
			std::string op = this->stk.top();
			
			if (!this->stk.empty()) 
       			this->stk.pop();  // Safe to pop
    		else 
        		return 1;
			
			// std::cout << "Top: " << this->stk.top() << std::endl;
			std::string operand2;
			if (!this->stk.empty()) 
				operand2 = this->stk.top();
			else 
        		return 1;

			
			if (!this->stk.empty()) 
       			this->stk.pop();  // Safe to pop
    		else 
        		return 1;

				
			// std::cout << "Top: " << this->stk.top() << std::endl;
			std::string operand1;

			
			if (!this->stk.empty()) 
				operand1 = this->stk.top();
			else 
        		return 1;

				
			if (!this->stk.empty()) 
       			this->stk.pop();  // Safe to pop
    		else 
        		return 1;

				
			this->stk.push(std::to_string(PerformOperation(operand1,operand2,op)));
		}
	}
	if(this->stk.size() != 1)
	{
		
		std::cout << "Failed stack size: " << this->stk.size()<< std::endl;
		return 1;
	}
	else
		std::cout << "Result: " << this->stk.top() << std::endl;
	
	// for(int i = 0; i < arg.size();i++)
	// {
		
	// }
	return 0;
}