/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 05:00:27 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/30 07:19:00 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	this->array = nullptr;
	this->size = 0;
	std::cout << "default const called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "parametrized const called" <<std::endl;
	this->array = new T[n];
	this->size = n;
	for(unsigned int i = 0; i < n ; i++)
		this->array[i] = 0;
}

template<typename T>
Array<T>::Array(Array<T> const & src)
{
	if (src.array)
	{
        this->array = new T[src.size];
		for (unsigned int i = 0; i < src.size;i++)
		{
			this->array[i] = src.array[i];
		}
    } else {
        this->array = nullptr;
		this->size = 0;
    }
}

template<typename T>
Array<T> const & Array<T>::operator=(Array<T> const & src)
{
	if (this != &src) {
        delete[] array;

        if (src.array) {
            this->array = new T[src.size];
            this->size = src.size;
            for (unsigned int i = 0; i < src.size; i++) {
                this->array[i] = src.array[i];
            }
        } else {
            this->array = nullptr;
            this->size = 0;
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int index)
{
    if (static_cast<unsigned int>(index) >= this->size) {
        throw std::out_of_range("Index out of range");
    }
    return this->array[index];
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
	std::cout << "destr called" << std::endl;
}