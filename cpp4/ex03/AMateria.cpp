/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:12:55 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/11/20 22:30:07 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() :type("Materia")
{
}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(AMateria const & materia) {
    *this = materia;
}

AMateria & AMateria::operator=(AMateria const & materia) {
    if (this != &materia)
        this->type = materia.type;
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}

