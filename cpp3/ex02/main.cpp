/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:37:06 by codespace         #+#    #+#             */
/*   Updated: 2024/09/14 13:15:38 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap bot2("asshole");
    bot2.attack("bro");
    bot2.takeDamage(70);
    bot2.takeDamage(29);
    bot2.attack("someone");
    bot2.beRepaired(200);
    bot2.attack("someone");
    bot2.gateGuard();

    
    return 0;
}