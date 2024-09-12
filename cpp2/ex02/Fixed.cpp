/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:51:55 by codespace         #+#    #+#             */
/*   Updated: 2024/09/12 17:00:35 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->decimal = 0;
}

Fixed::Fixed(Fixed const &copy)
{
    this->decimal = copy.decimal;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const integer)
{
    this->decimal = integer << this->fract;
    std::cout << "Int constructor called" << std::endl;

}


Fixed::Fixed(float const fl)
{
    this->decimal = roundf(fl * (1 << fract));
    std::cout << "this is decimal: " << this->decimal<< std::endl;
    std::cout << "Float constructor called" << std::endl;

}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & src)
{
    std::cout << "Copy assignement operator called" << std::endl;
    this->decimal = src.getRawBits();
    return *this;
}
//comparaison operators
bool Fixed::operator==(Fixed const & other) const
{
    return (this->decimal == other.decimal);
}

bool Fixed::operator!=(Fixed const & other) const
{
    return (!(*this == other));
}

bool Fixed::operator>=(Fixed const & other) const
{
    return (this->decimal >= other.decimal);
}
bool Fixed::operator<=(Fixed const & other) const
{
    return (this->decimal <= other.decimal);
}
bool Fixed::operator>(Fixed const & other) const
{
    return (this->decimal > other.decimal);
}
bool Fixed::operator<(Fixed const & other) const
{
    return (this->decimal < other.decimal);
}

//pre-increment operator
Fixed & Fixed::operator++(void) 
{
    this->decimal+=1;
    return *this;
}

//post-increment operator
Fixed Fixed::operator++(int) 
{
    Fixed temp = *this;
    this->decimal+=1;
    return temp;
}

Fixed & Fixed::operator--(void) 
{
    this->decimal-=1;
    return *this;
}

//post-increment operator
Fixed Fixed::operator--(int) 
{
    Fixed temp = *this;
    this->decimal-=1;
    return temp;
}

//arithmetic operators

Fixed Fixed::operator+(Fixed const & other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(Fixed const & other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}
Fixed Fixed::operator*(Fixed const & other) const
{
    Fixed result;
    result.setRawBits((this->getRawBits() * other.getRawBits())>>this->fract);
    return result;
}

Fixed Fixed::operator/(Fixed const & other) const
{
    Fixed result;
    result.setRawBits((this->getRawBits() / other.getRawBits())<<this->fract);
    return result;
}

//useless functions tbh
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


//functions to get either float representation or just int
float Fixed::toFloat(void) const 
{
    return (float)this->decimal / (1 << fract);  
}

int Fixed::toInt(void) const {
    return this->decimal >> fract;  
}


// << operator overload
std::ostream &operator<<(std::ostream & o, Fixed const &src)
{
    o << src.toFloat();
    return o;
}