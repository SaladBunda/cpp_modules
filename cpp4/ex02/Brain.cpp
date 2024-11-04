/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:01:06 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/27 20:37:19 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = "I have no idea";
	}	
	return ;
}

Brain::Brain(Brain const & src)
{	
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i) {
        this->ideas[i] = src.ideas[i];
    }
}

Brain & Brain::operator=(Brain const & src)
{
	for (int i = 0; i < 100; ++i) {
        this->ideas[i] = src.ideas[i];
    }
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}