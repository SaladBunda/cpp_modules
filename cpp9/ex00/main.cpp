/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:19:19 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/04 20:22:25 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
	if(ac == 2)
	{
		BitcoinExchange main;
		main.fill_data();
		return 0;
	}	
	else
		return(std::cout << "usage: ./btr <filename>" << std::endl,1);
}