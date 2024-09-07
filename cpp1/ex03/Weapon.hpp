/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:26:18 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/07 11:36:18 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon(void);
        ~Weapon(void);
        const std::string &getType(void);
        void setType(std::string type);
};

#endif