/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:43:46 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/31 16:25:59 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>


typedef unsigned int size_type;

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(MutantStack const & src);
		~MutantStack();
		MutantStack const & operator=(MutantStack const & src);
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		iterator begin();
    	iterator end();
    	const_iterator begin() const;
    	const_iterator end() const;
		bool empty() const;
		size_type size() const;
		T& top();
		const T & top() const;
		void push(const T& val);
		void pop();
};




#endif