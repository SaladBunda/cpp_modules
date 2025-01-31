/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:20:05 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/31 16:19:04 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>()
{
	std::cout << "Default const called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & src) /* : std::stack<T>(src)  */
{
	this->c = src.c;
	std::cout << "Cpy const called" << std::endl;
}

template<typename T>
MutantStack<T> const & MutantStack<T>::operator=(MutantStack<T> const & src)
{
	if(this != &src)
	{
		std::stack<T>::operator=(src);
	}
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "Destruct called" <<std::endl;
}

template<typename T>
typename std::deque<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename std::deque<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>
typename std::deque<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template<typename T>
typename std::deque<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

template<typename T>
bool MutantStack<T>::empty() const
{
	return std::stack<T>::empty();	
}

template<typename T>
size_type MutantStack<T>::size() const
{
	return std::stack<T>::size();
}

template <typename T>
T& MutantStack<T>::top()
{
	return std::stack<T>::top();
}
template<typename T>
const T & MutantStack<T>::top() const
{
	return std::stack<T>::top();
}

template <typename T>
void MutantStack<T>::push(const T& val)
{
	std::stack<T>::push(val);
}

template <typename T>
void MutantStack<T>::pop()
{
	std::stack<T>::pop();
}