/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:20:46 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/26 15:29:06 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal(void);
        Animal(std::string type);
        Animal(Animal const & src);
        Animal & operator=(Animal const & src);
        virtual ~Animal(void);
        std::string getType(void) const;
        virtual void makeSound(void) const;  
};
#endif