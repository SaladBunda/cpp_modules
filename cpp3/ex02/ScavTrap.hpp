/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:52:16 by codespace         #+#    #+#             */
/*   Updated: 2024/11/18 20:05:08 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
    
class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const & src);
        ~ScavTrap(void);
        ScavTrap & operator=(ScavTrap const & src);
        void attack(const std::string & target);
        void gateGuard(void);
};

#endif
