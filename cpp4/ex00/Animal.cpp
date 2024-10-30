/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:27:21 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/26 15:29:15 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal(std::string type)
{
    std::cout << "Animal string constructor is called" << std::endl;
    this->type = type;
}

Animal::Animal(Animal const & src)
{
    std::cout << "Animal copy constructor is called" << std::endl;
    this->type = src.type;
}

Animal & Animal::operator=(Animal const & src)
{
    this->type = src.type;
    return *this;
}

Animal::~Animal(void)
{
    std::cout << "Animal Destructor is called" << std::endl;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal noises idfk" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}