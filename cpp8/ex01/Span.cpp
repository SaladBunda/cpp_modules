/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:47:51 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/30 13:52:01 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->array = new int[N];
	for(int i = 0;i < N;i++)
		this->array[i] = 0;
}

Span::Span(Span const & src)
{
	if (src.array)
	{
        this->array = new int[src.array.length()];
		for (unsigned int i = 0; i < src.size;i++)
		{
			this->array[i] = src.array[i];
		}
    } else {
        this->array = nullptr;
		this->size = 0;
    }
}