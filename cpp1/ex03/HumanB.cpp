/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:44:41 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/11/04 21:56:38 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :name(name)
{
    this->weapon = NULL;
    return;
}

HumanB::~HumanB(void)
{
    return;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack(void)
{
    if(this->weapon == NULL)
    {
        std::cout << this->name << " has no weapon to attack with" << std::endl;
        return;
    }
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}