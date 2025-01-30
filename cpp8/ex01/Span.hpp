/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:34:47 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/30 13:53:44 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP


#include <iostream>
#include <algorithm>
#include <list>

class Span
{
	private:
		std::list<int> lst;
		Span(){};
	public:
		Span(unsigned int N);
		Span(Span const & src);
		~Span();
		void addNumber();
		int shortestSpan();
		int longestSpan();
};


#endif