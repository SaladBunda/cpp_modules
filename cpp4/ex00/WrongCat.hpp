/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:13:43 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/11/03 13:12:40 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP


# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    private:
        std::string _type;
        std::string* test;
    public:
        WrongCat(void);
        WrongCat(std::string type);
        WrongCat(WrongCat const & src);
        WrongCat & operator=(WrongCat const & src);
        ~WrongCat(void);
        void makeSound(void) const;  
};

#endif