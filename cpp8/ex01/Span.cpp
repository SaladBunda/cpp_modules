/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:47:51 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/30 16:53:54 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : N(N)
{
	if(N < 2)
		throw SizeTooSmall();
	std::cout << "constructor called" <<std::endl;
	
}

Span::Span(Span const & src)
{
	this->vec = src.vec;
}

Span const & Span::operator=(Span const & src)
{
	if(this != &src)
	{
		this->vec = src.vec;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Destructor called" <<std::endl;
}

void Span::addNumber(int n)
{
	if(this->vec.size() < this->N)
		this->vec.push_back(n);
	else
		throw std::out_of_range("Container is Full");
}

int Span::longestSpan()
{
	if(this->vec.size() < 2)
		throw SizeTooSmall();
	int max = *std::max_element(this->vec.begin(),this->vec.end());
	int min = *std::min_element(this->vec.begin(),this->vec.end());
	
	return max - min;
}

int Span::shortestSpan()
{
	if(this->vec.size() < 2)
		throw SizeTooSmall();
	std::sort<int>(this->vec.begin(),this->vec.end());
	int min = this->vec[1] - this->vec[0];
	for(unsigned long i = 0; i < this->vec.size() - 1;i++)
	{
		if(min > this->vec[i+1] - this->vec[i])
			min = this->vec[i+1] - this->vec[i];
	}
	return min;
	
}

void Span::fillVector()
{

	srand(time(nullptr));
	for(unsigned long i = 0; i < this->N;i++)
	{
		this->addNumber(rand() % 98765);
	}
}