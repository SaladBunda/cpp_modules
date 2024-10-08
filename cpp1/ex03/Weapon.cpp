/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:26:15 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/07 11:34:59 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

const std::string &Weapon::getType(void)
{
    const std::string &typeREF = this->type;
    return typeREF;
}