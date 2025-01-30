/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 05:32:02 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/30 07:56:50 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

void ll(void)
{
	system("leaks array");
}

int main()
{
	atexit(ll);
	Array<int> t= Array<int>(10);
	// std::cout << t[0] << std::endl;
	for(int i = 0; i < 10;i++)
	{
		t[i] = i + 20;
	}
	for(int i = 0; i < 10;i++)
	{
		std::cout << t[i] <<std::endl;
		// t[i] = i + 20;
	}
	// t[0] = 77;
}