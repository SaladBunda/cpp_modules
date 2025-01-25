/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:08:25 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/25 15:24:59 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <typeinfo>

int main()
{
	Base *random = generate();
	identify(random);
	identify(*random);
	std::cout << typeid(*random).name() << std::endl;
}