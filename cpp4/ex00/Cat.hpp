/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:33:07 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/26 15:28:36 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP


# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat(void);
        Cat(std::string type);
        Cat(Cat const & src);
        Cat & operator=(Cat const & src);
        ~Cat(void);
        void makeSound(void) const;  
};

#endif