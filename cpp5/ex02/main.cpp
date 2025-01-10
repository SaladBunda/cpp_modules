/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:49:22 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/10 22:39:36 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		// Form b("b28", 50,160);
		// Form c("b28", 151,160);
		Bureaucrat crat("yassin",50);

		
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	// Bureaucrat crat("bunda", 51);
	// a.beSigned(crat);
	// crat.signForm(a);
}