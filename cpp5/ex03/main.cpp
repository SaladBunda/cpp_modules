/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:49:22 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/13 11:39:23 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat bunda("bunda",20);
		AForm *form1 = new ShrubberyCreationForm("test");
		std::cout << "after creation" << std::endl;
		form1->beSigned(bunda);
		form1->execute(bunda);
		AForm *form2 = new RobotomyRequestForm("dak zamel");
		bunda.signForm(*form2);
		bunda.executeForm(*form2);		
		PresidentialPardonForm form3("Dean");
		for(int i = 0;i < 16;i++)
			bunda.Inc();
		form3.beSigned(bunda);
		form3.execute(bunda);
		bunda.executeForm(form3);
		
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
}