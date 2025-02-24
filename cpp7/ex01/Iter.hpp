/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:29:38 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/30 07:59:09 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP


template < typename T>
void iter(T array[], int len, void(*f)(T const &))
{
	for(int i = 0; i < len ;i++)
		f(array[i]);
}

template <typename T>
void inc(T & element)
{
	element++;
}


#endif