/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:37:06 by codespace         #+#    #+#             */
/*   Updated: 2024/09/13 20:26:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap bot("bunda");
    for(int i = 0;i < 20;i++)
        bot.attack("yassin");
    bot.takeDamage(60);
    bot.attack("bunda");

    ScavTrap bot2("bunda2");
    return 0;
}