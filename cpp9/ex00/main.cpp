/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:19:19 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/06 13:58:00 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
	if(ac == 2)
	{
		try
		{
    		std::string filename = av[1];
	
			BitcoinExchange main;
			main.fill_data_csv();
			main.get_from_file(filename);
		}
		catch(std::exception & e)
		{
			std::cout << "Exception catched: "<<e.what() << std::endl;
		}
	}	
	else
		return(std::cout << "usage: ./btr <filename>" << std::endl,1);
}