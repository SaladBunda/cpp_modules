/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:09:49 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/30 17:10:30 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main()
{
	try
	{
		Span sp = Span(95132168);
		sp.addNumber (-7);
		sp.addNumber(1513216600);
		for(int i = 0; i < 95132166;i++)
			sp.addNumber(i+ 5);
			
		// sp.fillVector();
		// sp.addNumber(17);
		// sp.addNumber();
		// sp.addNumber(9);
		// sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;


		
	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}