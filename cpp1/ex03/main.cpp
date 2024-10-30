/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:26:13 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/29 17:57:50 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon mase;
    mase.setType("mase");
    HumanA bunda("bunda", mase);
    bunda.attack();
    mase.setType("1911");
    bunda.attack();

    Weapon revolver;
    HumanB nabil("nabil");
    revolver.setType("Revolver");
    //nabil.setWeapon(revolver);
    nabil.attack();
    revolver.setType("Desert Eagle");
    nabil.attack();
    
}