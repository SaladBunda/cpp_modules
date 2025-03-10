/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:42:57 by codespace         #+#    #+#             */
/*   Updated: 2024/10/27 12:08:01 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string name;
        unsigned int Hp;
        unsigned int Ep;
        unsigned int Ad;
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const & src);
        ClapTrap & operator=(ClapTrap const & src);
        ~ClapTrap(void);
        void attack(const std::string & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


#endif/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:46:12 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/13 16:55:34 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string name;
        unsigned int Hp;
		unsigned int Ep;
		unsigned int Ad;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);
		ClapTrap & operator=(ClapTrap const & src);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif