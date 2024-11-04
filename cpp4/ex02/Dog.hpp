/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:00:04 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/30 21:26:02 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP


# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
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