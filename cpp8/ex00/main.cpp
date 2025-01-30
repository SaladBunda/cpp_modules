/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:34:36 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/30 13:23:29 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <string>

int main()
{
	std::list<int> lst;

	lst.push_back(77);
	lst.push_back(95);
	lst.push_back(9);
	lst.push_back(6318);
	lst.push_back(9614);
	// std::list<int>::iterator it = easyfind(lst,9);
	try
	{
		std::cout << *(easyfind(lst,77)) << std::endl;

	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
		
}