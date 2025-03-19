/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:49:22 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/10 22:04:20 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form a("a89",50,140);
		// Form b("b28", 50,160);
		// Form c("b28", 151,160);
		Bureaucrat crat("yassin",50);
		crat.signForm(a);
		crat.signForm(a);
		a.beSigned(crat);
		a.beSigned(crat);
		
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}