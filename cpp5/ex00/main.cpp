/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:49:22 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/10 22:13:05 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bunda;
		std::cout << bunda.getName() << std::endl;
		Bureaucrat test("bunda",150);
		test.Inc();
		std::cout << test.getGrade() << std::endl;
		Bureaucrat test2("zamel", 1);
		test2.Inc();
		std::cout << test2.getGrade() << std::endl;
		std::cout << test2 << std::endl;
		
	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}