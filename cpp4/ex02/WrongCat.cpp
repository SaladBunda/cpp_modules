/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:14:43 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/26 16:15:15 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "WrongCat default constructor is called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(std::string type)
{
    std::cout << "WrongCat string constructor is called" << std::endl;
    this->type = type;
}

WrongCat::WrongCat(WrongCat const & src)
{
    std::cout << "WrongCat copy constructor is called" << std::endl;
    this->type = src.type;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
    this->type = src.type;
    return *this;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat Destructor is called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Meooooooow!!!" << std::endl;
}