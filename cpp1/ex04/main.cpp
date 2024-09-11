/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:21:55 by codespace         #+#    #+#             */
/*   Updated: 2024/09/11 18:57:43 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int ac, char **av)
{
    if(ac == 4)
    {
        (void) av;
        std::string buffer;
        std::ifstream input(av[1]);
        if(input.is_open() == false)
        {
            std::cout << "Failed to open file" << std::endl;
            return 1;
        }
        int i =0;
        int j = 0;
        int tmp;
        std::ofstream out("result.replace");
        while(std::getline(input,buffer))
        {
            i = 0;
            while(buffer[i])
            {
                j = 0;
                if(buffer[i] == av[2][j])
                {
                    tmp = i;
                    while(buffer[i] && av[2][j] && buffer[i] == av[2][j])
                    {
                        j++;
                        i++;
                    }
                    if(av[2][j] == '\0')
                    {
                        out << av[3];
                        continue;   
                    }
                    else 
                    {
                        i=tmp;
                      out << buffer[i];
                      i++;
                      continue;
                    }
                }
                else
                    out << buffer[i];
                i++;
            }
            // std::cout << buffer << std::endl;
            out << std::endl;
        }
    }
    else
        std::cout << "Usage: ./sed <filename> <s1> <s2>" << std:: endl;
}