/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:28:11 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/01 20:22:55 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
    Phonebook start;
    std::string line;
    std::cout << "Welcome to Phonebook, pick one of the three commands: ADD SEARCH EXIT" << std::endl;
    std::getline(std::cin, line);
    std::cout << "result: " << line << std::endl;
    if(line == "ADD")
        std::cout << "deal" << std::endl;
    else if(line == "EXIT")
        std::cout << "fuck off" << std::endl;
    else if(line == "SEARCH")
        std::cout<< "look for it urself" << std::endl;
    
    return 0;
    
    
    
}