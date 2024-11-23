/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:19:59 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/11/23 15:57:37 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "Materia.hpp"
#include "ICharacter.hpp"

class Cure : public Materia {
    public:
        Cure();
        Cure(const Cure& src);
        virtual ~Cure();
        Cure& operator=(const Cure& src);
        AMateria* clone() const;
        void use(ICharacter& target);
		void setType(std::string & type);
};

#endif
