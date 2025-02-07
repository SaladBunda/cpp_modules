/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:13:38 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/07 20:23:29 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int ac, char **av)
{
	if(ac == 2)
	{
		RPN main;
		std::string arg = av[1];
		if(main.ParseArg(arg) == 1)
			std::cout << "Error\n";
	}
	else
		std::cout << "Usage: ./RPN \"expression\"" << std::endl;
}
