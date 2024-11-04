/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:21:55 by codespace         #+#    #+#             */
/*   Updated: 2024/11/04 17:38:15 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl john;
    if (ac == 2)
    {
   		john.complain(av[1]);
    }
	else
	    return(std::cout << "usage: ./harlFilter <level>" << std::endl, 1);
}