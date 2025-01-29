/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:29:38 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/29 02:56:55 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP


template < typename T, typename Z >
void iter(T *array, int len, void(*f)(Z &))
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