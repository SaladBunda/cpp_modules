/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:34:16 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/21 17:55:41 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	std::time_t start = std::clock();
	(void) ac;
	PmergeMe main;
	if(main.FillArray(av) == 1)
		return 1;
	int power = main.Merge();
	main.Insert(power / 2);
	std::cout << "End result: ";
	for(std::vector<std::string>::iterator it = main.vec.begin();it != main.vec.end();it++)
		std::cout << *it << " "; 
	std::cout << std::endl;
	std::time_t end = std::clock();
	std::cout << "Time Elapsed: " <<double(end - start)/CLOCKS_PER_SEC * 1000 * 100 <<"us"<< std::endl;
	
}