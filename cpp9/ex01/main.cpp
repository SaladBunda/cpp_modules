/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:13:38 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/08 17:11:55 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void ll(void)
{
	system("leaks RPN");

}


int main(int ac, char **av)
{
	atexit(ll);
	if(ac == 2)
	{
		int * ntr = new int;
		RPN main;
		(void) ntr;
		delete ntr;
		std::string arg = av[1];
		if(main.ParseArg(arg) == 1)
			std::cout << "Error\n";
	}
	else
		std::cout << "Usage: ./RPN \"expression\"" << std::endl;
}
