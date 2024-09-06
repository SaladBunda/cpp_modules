/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:24:58 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/06 11:05:47 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie
{
    private:
        std::string name;
        
    public:
        // Zombie(std::string name);
        Zombie(void);
        ~Zombie(void);
        void setName(std::string name);
        void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif