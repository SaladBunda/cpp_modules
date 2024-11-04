/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:00:55 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/27 12:56:25 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    std::cout << "Dog default constructor is called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(std::string type)
{
    std::cout << "Dog string constructor is called" << std::endl;
    this->type = type;
    this->brain = new Brain();
}

Dog::Dog(Dog const & src)
{
    std::cout << "Dog copy constructor is called" << std::endl;
    this->type = src.type;
    this->brain = src.brain;
}

Dog & Dog::operator=(Dog const & src)
{
    this->type = src.type;
    this->brain = src.brain;
    return *this;
}

Dog::~Dog(void)
{
    std::cout << "Dog Destructor is called" << std::endl;
    delete this->brain;
}

void Dog::makeSound(void) const
{
    std::cout << "Whoooof whoooof!!!" << std::endl;
}