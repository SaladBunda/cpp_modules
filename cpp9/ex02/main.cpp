/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:34:16 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/15 21:41:45 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	(void) ac;
	PmergeMe main;
	if(main.FillArray(av) == 1)
		return 1;
	int power = main.Merge();
	main.Insert(power / 2);
	
}