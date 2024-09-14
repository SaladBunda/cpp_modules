/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:21:55 by codespace         #+#    #+#             */
/*   Updated: 2024/09/14 16:41:35 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int ac, char **av)
{
    if(ac == 4)
    {
        std::string buffer;
        std::string to_find = av[2];
        if(to_find.empty() == true)
        {
            std::cout << "needle cant be empty" << std::endl;
            return 1;
        }
        std::ifstream input(av[1]);
        
        std::string filename = av[1];
        if(input.is_open() == false)
        {
            std::cout << "Failed to open file" << std::endl;
            return 1;
        }
        size_t pos = 1;
        std::ofstream out(filename += ".replace");
        while(std::getline(input,buffer))
        {
            pos = buffer.find(av[2]);
            while(pos != std::string::npos)
            {
                pos = buffer.find(av[2]);
                if(pos == std::string::npos)
                {
                    std::cout << " no more needle" << std::endl;
                    break;
                }
                std::cout << pos <<std::endl;
                buffer.erase(pos,to_find.length());
                buffer.insert(pos, av[3]);
            }
            out << buffer;
            out << std::endl;
            buffer.clear();
                
        }
    }
    else
        std::cout << "Usage: ./sed <filename> <s1> <s2>" << std:: endl;
}
