/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:19:47 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/02 16:35:14 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Phonebook::Phonebook(void)
{
    this->num = 0;
    this->current = 0;
    return;
}

Phonebook::~Phonebook(void)
{
    return;
}

int check_number(std::string str)
{
    int i = 0;
    if(str[i]=='+')
        i++;
    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return 1;
    }
    return 0;
}

void Phonebook::add_contact(void)
{
    std::string line;
    int i = 0;
    while(i < 5)
    {
        if(i == 0)
        {
            std::cout << "enter first name: ";
            std::getline(std::cin, line);
            if(std::cin.eof() == true)
                return ;
            if(line == "")
            {
                std::cout << "first name cant be empty" << std::endl;
                line.clear();
                continue;
            }
            else
            {
                this->contacts[this->current % 8].first_name = line;
                i++;
            }
        }
        else if(i == 1)
        {
            std::cout << "enter last name: ";
            std::getline(std::cin, line);
            if(std::cin.eof() == true)
                return ;
            if(line == "")
            {
                std::cout << "last name cant be empty" << std::endl;
                line.clear();
                continue;
            }
            else
            {
                this->contacts[this->current % 8].last_name = line;
                i++;
            }
        }
        else if(i == 2)
        {
            std::cout << "enter nickname: ";
            std::getline(std::cin, line);
            if(std::cin.eof() == true)
                return ;
            if(line == "")
            {
                std::cout << "nickname cant be empty" << std::endl;
                line.clear();
                continue;
            }
            else
            {
                this->contacts[this->current % 8].nickname = line;
                i++;
            }
        }
        else if(i == 3)
        {
            std::cout << "enter number ";
            std::getline(std::cin, line);
            if(std::cin.eof() == true)
                return ;
            if(line == "")
            {
                std::cout << "number cant be empty" << std::endl;
                line.clear();
                continue;
            }
            else
            {
                if(check_number(line) == 1)
                {
                    std::cout << "wrong number" << std::endl;
                    line.clear();
                    continue;
                }
                this->contacts[this->current % 8].number = line;
                i++;
            }
        }
        else if(i == 4)
        {
            std::cout << "enter darkest secret: ";
            std::getline(std::cin, line);
            if(std::cin.eof() == true)
                return ;
            if(line == "")
            {
                std::cout << "darkest secret cant be empty" << std::endl;
                line.clear();
                continue;
            }
            else
            {
                this->contacts[this->current % 8].darkest_secret = line;
                i++;
            }
        }
        
        
    }
    this->current++;
    std::cout << this->current << std::endl;
}