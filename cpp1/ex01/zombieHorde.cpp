/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:18:47 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/11/04 14:48:51 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if(N <= 0)
		return NULL;
    Zombie *zombies = new Zombie[N];
    for(int i=0;i < N;i++)
        zombies[i].setName(name);
    
    return zombies;
}