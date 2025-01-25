/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:20:23 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/25 12:55:52 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{

	Data *str = new Data;
	std::cout << str << std::endl;
	str->name = "bruh";
	uintptr_t serz = Serializer::serialize(str);
	Data* deserz = Serializer::deserialize(serz);
	std::cout << deserz << std::endl;
	std::cout << deserz->name << std::endl;
	
	// return 0;
}