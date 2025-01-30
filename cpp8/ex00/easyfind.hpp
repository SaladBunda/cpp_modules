/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:32:38 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/30 13:22:34 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <algorithm>
#include <list>



class NotFoundException : public std::exception {
public:
    const char* what() const throw()
	{
        return "Element not found";
    }
};

template<typename T>
typename T::iterator easyfind(T & arr, int to_find)
{
	typename T::iterator it = arr.begin();
	if(std::find(it,arr.end(),to_find) == arr.end() && *arr.end() != to_find)
		throw NotFoundException();
	return(std::find(it,arr.end(),to_find));
}


	// for(it ; it !=arr.end();it++)
	// {
	// 	if(*it == to_find)
	// 		return it;
	// }
	


#endif