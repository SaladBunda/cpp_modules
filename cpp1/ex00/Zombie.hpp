/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:24:58 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/05 19:31:57 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie
{
    public:
    Zombie(std::string name);
    ~Zombie(void);
    void announce(void);

    private:
    std::string name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif