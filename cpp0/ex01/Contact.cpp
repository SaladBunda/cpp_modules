/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:08:46 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/22 11:11:21 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
    this->number = "";
    this->first_name= "";
    this->last_name= "";
    this->nickname= "";
    this->darkest_secret= "";
    this->index = 1;
    return;
}

Contact::~Contact(void)
{
    return;
}