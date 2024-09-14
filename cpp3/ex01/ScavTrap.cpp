/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:13:41 by codespace         #+#    #+#             */
/*   Updated: 2024/09/13 20:37:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->Ad= 10;
    this->Hp = 100;
    this->Ep = 50;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap naming constructor called" << std::endl;
    this->name = name;
    this->Ad= 10;
    this->Hp = 100;
    this->Ep = 50;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
    std::cout << "ScavTrap copying constructor called" << std::endl;
    // this->name = src.name;
    this->Ad= src.Ad;
    this->Hp = src.Hp;
    this->Ep = src.Ep;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
{
    this->name = src.name;
    this->Ad= src.Ad;
    this->Hp = src.Hp;
    this->Ep = src.Ep;
    return *this;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string & target)
{
    if(this->Hp > 0 && this->Ep > 0)
    {
        this->Ep--;
        std::cout << "ScavTrap " << this->name << " attacks " <<target<< ", causing "<<this->Ad<<" points of damage!"<<std::endl;
    }
    else
        std::cout << "Unable to attack" << std::endl;
}

void ScavTrap::gateGuard(void)
{
    std::cout << " ScavTrap is now in Gate keeper mode." << std::endl;
}