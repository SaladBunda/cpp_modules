/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:49:26 by codespace         #+#    #+#             */
/*   Updated: 2024/09/13 19:05:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    std::cout << "Default Contructor called" << std::endl;
    this->Hp = 10;
    this->Ep = 10;
    this->Ad= 10;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    this->name = src.name;
    this->Ad = src.Ad;
    this->Hp = src.Hp;
    this->Ep = src.Ep;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
    this->name = src.name;
    this->Ad = src.Ad;
    this->Hp = src.Hp;
    this->Ep = src.Ep;
    return *this;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(amount > this->Hp)
        this->Hp = 0;
    else
        this->Hp -= amount;
}

void ClapTrap::attack(const std::string & target)
{
    if(this->Hp > 0 && this->Ep > 0)
    {
        this->Ep--;
        std::cout << "ClapTrap " << this->name << " attacks " <<target<< ", causing "<<this->Ad<<" points of damage!"<<std::endl;
    }
    else
        std::cout << "Unable to attack" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->Hp > 0 && this->Ep > 0)
    {
        this->Hp += amount;
    }
    else
        std::cout << "Unable to attack" << std::endl;

}