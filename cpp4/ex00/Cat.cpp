/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:14:21 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/26 15:31:55 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat default constructor is called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(std::string type)
{
    std::cout << "Cat string constructor is called" << std::endl;
    this->type = type;
}

Cat::Cat(Cat const & src)
{
    std::cout << "Cat copy constructor is called" << std::endl;
    this->type = src.type;
}

Cat & Cat::operator=(Cat const & src)
{
    this->type = src.type;
    return *this;
}

Cat::~Cat(void)
{
    std::cout << "Cat Destructor is called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Meooooooow!!!" << std::endl;
}