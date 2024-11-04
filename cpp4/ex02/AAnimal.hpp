/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:20:46 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/30 21:25:18 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal(void);
        AAnimal(std::string type);
        AAnimal(AAnimal const & src);
        AAnimal & operator=(AAnimal const & src);
        virtual ~AAnimal(void);
        std::string getType(void) const;
        virtual void makeSound(void) const = 0;  
};
#endif