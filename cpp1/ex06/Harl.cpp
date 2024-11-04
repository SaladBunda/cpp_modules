/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:01:42 by codespace         #+#    #+#             */
/*   Updated: 2024/11/04 17:43:45 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]"<<std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]"<<std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]"<<std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]"<<std::endl;
    std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::other(void)
{
    std::cout <<  "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain(std::string level)
{
    Harl obj;
    void (Harl::*pointer[])()={&Harl::debug, &Harl::info,&Harl::warning,&Harl::error, &Harl::other};
    std::string option[] = {"DEBUG","INFO", "WARNING", "ERROR"};
    int i = 0;
    while(level != option[i] && i<4)
        i++;
    switch (i)
    {
        case 0:
            (obj.*pointer[i++])();
        case 1:
            (obj.*pointer[i++])();
        case 2:
            (obj.*pointer[i++])();
        case 3:
            (obj.*pointer[i++])();
            break ;
        default:
            (obj.*pointer[i])();
    }    
}
