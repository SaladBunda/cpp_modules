/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:00:55 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/26 15:32:09 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    std::cout << "Dog default constructor is called" << std::endl;
}

Dog::Dog(std::string type)
{
    std::cout << "Dog string constructor is called" << std::endl;
    this->type = type;
}

Dog::Dog(Dog const & src)
{
    std::cout << "Dog copy constructor is called" << std::endl;
    this->type = src.type;
}

Dog & Dog::operator=(Dog const & src)
{
    this->type = src.type;
    return *this;
}

Dog::~Dog(void)
{
    std::cout << "Dog Destructor is called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Whoooof whoooof!!!" << std::endl;
}