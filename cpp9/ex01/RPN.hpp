/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:14:00 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/07 20:36:18 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>



class DivisionByZeroException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("You cant divide by zero");
		}
};


class RPN
{
	public:
		std::stack<std::string> stk;
		RPN(void);
		RPN(RPN const & src);
		~RPN();
		RPN const & operator=(RPN const & src);
		int ParseArg(std::string arg);
		
};
int TestArgChar(std::string arg);
int PerformOperation(std::string opd1,std::string opd2, std::string op);

#endif