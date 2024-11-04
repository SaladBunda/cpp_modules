/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:24:37 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/11/04 14:51:39 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int n = 3;
    Zombie *array  = zombieHorde(n, "bunda");
	for(int i=0;i<n;i++)
		array[i].announce();
    delete[] array;
}