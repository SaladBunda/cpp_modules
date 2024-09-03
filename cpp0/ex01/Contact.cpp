/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:08:46 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/02 16:27:27 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(void)
{
    this->number = "";
    this->first_name="";
    this->last_name="";
    this->nickname="";
    this->darkest_secret="";
    this->index = 1;
    // std::cout << "created a contact" << std::endl;
    return;
}

Contact::~Contact(void)
{
    // std::cout << "done" << std::endl;
    return;
}