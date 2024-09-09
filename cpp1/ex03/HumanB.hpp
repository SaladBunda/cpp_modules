/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:24:44 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/07 20:47:15 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void setWeapon(Weapon &weapon);
        void attack(void);
};

#endif