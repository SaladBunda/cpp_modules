/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:13:41 by codespace         #+#    #+#             */
/*   Updated: 2024/11/17 22:46:30 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->name = "Fraggy";
    this->Ad= 30;
    this->Hp = 100;
    this->Ep = 10;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap naming constructor called" << std::endl;
    this->name = name;
    this->Ad= 30;
    this->Hp = 100;
    this->Ep = 10;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
    std::cout << "FragTrap copying constructor called" << std::endl;
    this->name = src.name;
    this->Ad= src.Ad;
    this->Hp = src.Hp;
    this->Ep = src.Ep;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
{
    this->name = src.name;
    this->Ad= src.Ad;
    this->Hp = src.Hp;
    this->Ep = src.Ep;
    return *this;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string & target)
{
    if(this->Hp > 0 && this->Ep > 0)
    {
        this->Ep--;
        std::cout << "FragTrap " << this->name << " attacks " <<target<< ", causing "<<this->Ad<<" points of damage!"<<std::endl;
    }
    else
        std::cout << "Unable to attack" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "HIGH FIVE!!!!" << std::endl;
}