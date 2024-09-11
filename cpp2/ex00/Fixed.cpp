/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:51:55 by codespace         #+#    #+#             */
/*   Updated: 2024/09/10 19:09:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->decimal = 0;
}

Fixed::Fixed(Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed & src)
{
    std::cout << "Copy assignement operator called" << std::endl;
    this->decimal = src.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits called" << std::endl;
    return this->decimal;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits called" << std::endl;
    this->decimal = raw;
}