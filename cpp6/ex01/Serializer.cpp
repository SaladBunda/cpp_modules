/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:42:06 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/25 12:24:33 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(Serializer const & src)
{
	(void) src;
	return ;
}

Serializer const & Serializer::operator=(Serializer const & src)
{
	(void) src;
	return *this;
}

Serializer::~Serializer(void)
{
	return ;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t x = reinterpret_cast<uintptr_t>(ptr);
	return x;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *var = reinterpret_cast<Data*>(raw);
	return var;
}