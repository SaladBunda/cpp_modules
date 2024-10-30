/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:14:21 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/27 12:56:10 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat default constructor is called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(std::string type)
{
    std::cout << "Cat string constructor is called" << std::endl;
    this->type = type;
    this->brain = new Brain();
}

Cat::Cat(Cat const & src)
{
    std::cout << "Cat copy constructor is called" << std::endl;
    this->type = src.type;
    this->brain = src.brain;
}

Cat & Cat::operator=(Cat const & src)
{
    this->type = src.type;
    this->brain = src.brain;
    return *this;
}

Cat::~Cat(void)
{
    std::cout << "Cat Destructor is called" << std::endl;
    delete this->brain;
}

void Cat::makeSound(void) const
{
    std::cout << "Meooooooow!!!" << std::endl;
}