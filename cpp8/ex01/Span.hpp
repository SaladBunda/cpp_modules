/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:34:47 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/30 16:50:45 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP


#include <iostream>
#include <algorithm>
#include <vector>


class SizeTooSmall: public std::exception
{
public:
    const char* what() const throw()
	{
        return "Size must be greater than or equal to 2";
    }
};

class Span
{
	private:
		unsigned int N;
		std::vector<int> vec;
		Span(){};
	public:
		Span(unsigned int N);
		Span(Span const & src);
		~Span();
		Span const & operator=(Span const & src);
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void fillVector();
};


#endif