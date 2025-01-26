/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:38:01 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/26 18:47:59 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP


template< typename T>
T max(T x, T y)
{
	return (x>y ? x : y);
}

template< typename T>
T min (T x, T y)
{
	return (x<y ? x : y);
}


template< typename T>
void swap(T & x, T & y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

#endif