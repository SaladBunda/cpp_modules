/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:41:34 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/18 21:13:25 by ael-maaz         ###   ########.fr       */
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
	std::string label;
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
		int Sort(std::vector<t_help> main, std::vector<t_help> pend,std::vector<t_help> odd,std::vector<t_help> extra);
};

int TestArguments(std::string str, std::vector<std::string> vec);
std::string giveLabel(int i);

#endif