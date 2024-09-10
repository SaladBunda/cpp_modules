/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:01:42 by codespace         #+#    #+#             */
/*   Updated: 2024/09/10 14:44:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    Harl obj;
    void (Harl::*pointer[])()={&Harl::debug, &Harl::info,&Harl::warning,&Harl::error};
    std::string option[] = {"DEBUG","INFO", "WARNING", "ERROR"};
    int i = 0;
    while(i<4)
    {
        if(option[i] == level)
        {
            (obj.*pointer[i])();
            return;
        }
        i++;
    }
    if(i>=4)
        std::cout << "just complaining" << std::endl;  
    
}
