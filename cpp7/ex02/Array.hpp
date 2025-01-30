/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 04:17:44 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/30 06:09:17 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		unsigned int size;
		T *array;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & src);
		Array const & operator=(Array const & src);
		~Array(void);
		T &operator[](int index);
		
		
};

#endif