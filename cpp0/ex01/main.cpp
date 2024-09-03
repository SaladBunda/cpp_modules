/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:28:11 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/02 16:38:39 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
    Phonebook start;
    std::string line;
    std::cout << "Welcome to Phonebook" << std::endl;
    while(line != "EXIT" && std::cin.eof() == false)
    {
        std::cout << "Pick one of the three commands: ADD SEARCH EXIT" << std::endl;
        std::getline(std::cin, line);
        if(line == "ADD")
            start.add_contact();
        else if(line == "EXIT")
            std::cout << "fuck off" << std::endl;
        else if(line == "SEARCH")
            start.search_contact();  
    }
    return 0;
}