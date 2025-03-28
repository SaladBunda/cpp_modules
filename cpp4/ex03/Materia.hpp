/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:47:48 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/11/23 16:16:12 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_HPP
# define MATERIA_HPP


#include "AMateria.hpp"

class Materia : public AMateria
{
    public:
        Materia();
        Materia(std::string const & type);
        Materia(Materia const & src);
        Materia & operator=(Materia const & src);
        ~Materia();
        virtual AMateria* clone() const;
		void setType(std::string & type);
        virtual void use(ICharacter& target);
};



#endif