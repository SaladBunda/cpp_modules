/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:41:34 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/03/05 02:37:56 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>

#define FULL 1
#define NOT_FULL 0

typedef struct s_help
{
	int info;
	std::vector<int> vect;
	std::string label;
} t_help;

class PmergeMe
{
	// private:
	public:
		std::time_t start;
		std::time_t checkpoint;
		std::deque<int> que;	
		std::vector<int> vec;
		PmergeMe();
		PmergeMe(PmergeMe const & src);
		~PmergeMe();
		PmergeMe const & operator=(PmergeMe const & src);
		int FillArray(char **av);
		int Merge();
		int Insert(int power);
		int Sort(std::vector<t_help> main, std::vector<t_help> pend,std::vector<t_help> odd,std::vector<t_help> extra, int power);
};

int TestArguments(std::string str, std::vector<int> vec);
std::string giveLabel(int i);
int nextJacobsthal(int prev, int prevPrev);
int findMatchInMain(const std::vector<t_help>& main, const std::string& bLabel);
void printVector(const std::vector<t_help>& vec, const std::string& name);
void PushToVector(std::vector<t_help>& main, std::vector<int>& vec);
void BinarySearchSort(std::vector<t_help>& main, std::vector<t_help>& vector, int end);
int recursion2(std::vector<t_help>& main, std::vector<t_help>& vector, int index, int start, int end);


#endif