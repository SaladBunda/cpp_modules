/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:37:06 by codespace         #+#    #+#             */
/*   Updated: 2024/11/18 18:57:33 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap bot2("asshole");
    FragTrap bot1("hero");
    bot2.attack("bro");
    bot2.takeDamage(70);
    bot2.takeDamage(29);
    bot2.attack("someone");
    bot2.beRepaired(200);
    bot2.attack("someone");
    bot2.gateGuard();
    bot1.attack("bro");
    bot1.takeDamage(-1);
    bot1.takeDamage(29);
    bot1.attack("someone");
    bot1.highFivesGuys();
    
    return 0;
}