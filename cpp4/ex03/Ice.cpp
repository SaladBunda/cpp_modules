/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:16:06 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/11/23 16:41:41 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "Ice";
}

Ice::Ice(const Ice & src)
{
	this->type = src.getType();
}

Ice & Ice::operator=(const Ice & src)
{
	this->type = src.getType();
	return *this;
}

AMateria* Ice::clone() const
{
	AMateria * clone = new Ice();
	return(clone);
}

void Ice::use (ICharacter & target)
{
	std::cout << "* heals shoots an ice bolt at " << target.getName() << " *" <<std::endl; 
}