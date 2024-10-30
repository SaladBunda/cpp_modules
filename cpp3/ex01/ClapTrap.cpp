/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:49:26 by codespace         #+#    #+#             */
/*   Updated: 2024/10/27 12:07:56 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    std::cout << "ClapTrap Default Contructor called" << std::endl;
    this->Hp = 10;
    this->Ep = 10;
    this->Ad= 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap Naming Contructor called" << std::endl;
    this->name = name;
    this->Hp = 10;
    this->Ep = 10;
    this->Ad= 0;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << "ClapTrap Copy Contructor called" << std::endl;

    this->name = src.name;
    this->Ad = src.Ad;
    this->Hp = src.Hp;
    this->Ep = src.Ep;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor called" << std::endl;
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
    if(this->Hp)
    {
        if(amount > this->Hp)
            this->Hp = 0;
        else
            this->Hp -= amount; 
        std::cout << "Took " << amount << " of damage!!" << std::endl;  
    }
    else
        std::cout << "Cant take damage cuz it dead alr" << std::endl;
    
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
        this->Ep--;
        this->Hp += amount;
        std::cout << this->name << " repaired for: " << amount << std::endl;
    }
    else
        std::cout << "Unable to repair" << std::endl;
}