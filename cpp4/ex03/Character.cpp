/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:51:23 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/11/23 17:13:54 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"

Character::Character()
{
    std::cout << "Character default constructor called" << std::endl;
    this->name = "Character";
    for(int i = 0;i < 4 ; i++)
        this->inventory[i] = NULL;
}

Character::Character(std::string const &name)
{
    this->name = name;
    for(int i = 0;i < 4 ; i++)
        this->inventory[i] = NULL;
}

Character::Character(Character const &character)
{
    std::cout << "Character Copy constructor called" << std::endl;
    this->name = character.name;
    
    for(int i = 0;i < 4 ; i++)
    {
        if(this->inventory[i])
            delete this->inventory[i];
        this->inventory[i] = character.inventory[i]->clone();
    }
}