/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:27:21 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/26 15:29:15 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    std::cout << "AAnimal default constructor is called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
    std::cout << "AAnimal string constructor is called" << std::endl;
    this->type = type;
}

AAnimal::AAnimal(AAnimal const & src)
{
    std::cout << "AAnimal copy constructor is called" << std::endl;
    this->type = src.type;
}

AAnimal & AAnimal::operator=(AAnimal const & src)
{
    this->type = src.type;
    return *this;
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal Destructor is called" << std::endl;
}

std::string AAnimal::getType(void) const
{
    return (this->type);
}