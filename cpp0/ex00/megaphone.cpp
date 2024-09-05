/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:38:57 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/08/31 15:32:25 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string arg;
    int i = 1;
    size_t j;
    if(ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    
    while(i < ac)
    {
        arg = av[i];
        j = 0;
        while(j < arg.size())
        {
            if(arg[j]>='a' && arg[j]<='z')
                arg.replace(j,1,1,arg[j] - 32);
            j++;
        }
        std::cout << arg ;
        i++;
    }
    std::cout << std::endl;
}