/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:41:34 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/15 22:13:18 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

#define FULL 1
#define NOT_FULL 0

typedef struct s_help
{
	int info;
	std::vector<std::string> vect;
} t_help;

class PmergeMe
{
	private:
		std::vector<std::string> vec;
		std::deque<int> que;
	public:
		PmergeMe();
		PmergeMe(PmergeMe const & src);
		~PmergeMe();
		PmergeMe const & operator=(PmergeMe const & src);
		int FillArray(char **av);
		int Merge();
		int Insert(int power);
};

int TestArguments(std::string str, std::vector<std::string> vec);


#endif