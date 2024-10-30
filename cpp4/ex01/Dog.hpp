/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:00:04 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/27 11:45:36 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP


# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
    private:
        Brain *brain;
    public:
        Dog(void);
        Dog(std::string type);
        Dog(Dog const & src);
        Dog & operator=(Dog const & src);
        ~Dog(void);
        void makeSound(void) const;  
};

#endif