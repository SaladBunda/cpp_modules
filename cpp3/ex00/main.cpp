/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:37:06 by codespace         #+#    #+#             */
/*   Updated: 2024/11/17 19:24:21 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot("bunda");
    for(int i = 0;i < 9;i++)
        bot.attack("yassin");
    bot.takeDamage(9);
    bot.beRepaired(10);
    bot.takeDamage(9);
    bot.attack("bunda");
    return 0;
}