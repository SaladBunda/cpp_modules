/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:59:09 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/11/23 16:38:46 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

Materia::Materia()
{
    std::cout << "Materia Default constructor" << std::endl;
    this->type = "DMateria";
}

Materia::Materia(std::string const & type)
{
    this->type = type;
}

Materia::Materia(Materia const & src)
{
    this->type = src.getType();
}

Materia & Materia::operator=(Materia const & src)
{
    this->type = src.getType();
	return *this;
}

AMateria * Materia::clone() const
{
	AMateria * clone = new Materia(this->type);
	return clone;
}


void Materia::use(ICharacter& target)
{
	std::cout << "Materia use called" << std::endl; 
}