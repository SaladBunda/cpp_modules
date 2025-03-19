/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:21:55 by codespace         #+#    #+#             */
/*   Updated: 2025/02/05 20:36:31 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int replace(char **av)
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
    const char *filename2 = (filename += ".replace").c_str();
    std::ofstream out(filename2);
	if(out.is_open() == false)
    {
        std::cout << "Failed to create output file" << std::endl;
        return 1;
    }
    while(std::getline(input,buffer, '\0'))
    {
        pos = buffer.find(av[2]);
        while(pos != std::string::npos)
        {
            pos = buffer.find(av[2]);
            if(pos == std::string::npos)
                break;
            buffer.erase(pos,to_find.length());
            buffer.insert(pos, av[3]);
        }
        out << buffer;
        buffer.clear();
    }
	return 0;
}

int main(int ac, char **av)
{
    if(ac == 4)
    {
       return(replace(av));
    }
    else
        std::cout << "Usage: ./sed <filename> <s1> <s2>" << std:: endl;
}
