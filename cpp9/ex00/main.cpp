/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:19:19 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/05 20:27:59 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
	if(ac == 2)
	{
		try
		{
			
		std::ifstream input(av[1]);
    
    	std::string filename = av[1];
		if(input.is_open() == false)
       		throw OpenFailure();
		// BitcoinExchange main;
		// main.fill_data();
		parse_date(av[1]);
		return 0;
		}
		catch(std::exception & e)
		{
			std::cout << "Exception catched: "<<e.what() << std::endl;
		}
	}	
	else
		return(std::cout << "usage: ./btr <filename>" << std::endl,1);
}