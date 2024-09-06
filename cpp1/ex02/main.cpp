/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:09:18 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/06 19:04:44 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string &stringREF = brain;
    std::string *stringPTR = &brain;
    std::cout << "variable: "<< &brain << std::endl << "pointer: " << stringPTR <<std::endl << "ref: " << &stringREF <<std::endl;
    std::cout << brain << std::endl << stringREF <<std::endl << *stringPTR <<std::endl;
}