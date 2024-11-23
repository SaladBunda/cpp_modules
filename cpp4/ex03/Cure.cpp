/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:20:15 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/11/23 16:38:57 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(const Cure & src)
{
	this->type = src.getType();
}

Cure & Cure::operator=(const Cure & src)
{
	this->type = src.getType();
	return *this;
}

AMateria* Cure::clone() const
{
	AMateria * clone = new Cure();
	return(clone);
}

void Cure::use (ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" <<std::endl; 
}