/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:29:04 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/05 20:28:05 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}
Zombie::Zombie(std::string name)
{
    this->name = name;
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << ": is gone forever" << std::endl;
    return ;
}