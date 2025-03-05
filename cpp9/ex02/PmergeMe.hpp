/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:41:34 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/03/05 23:49:04 by ael-maaz         ###   ########.fr       */
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

typedef struct s_vec
{
	int info;
	std::vector<int> vect;
	std::string label;
} t_vec;

typedef struct s_deque
{
	int info;
	std::deque<int> vect;
	std::string label;
} t_deque;

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
		int FillArrayVec(char **av);
		int MergeVec();
		int InsertVec(int power);
		int SortVec(std::vector<t_vec> main, std::vector<t_vec> pend,std::vector<t_vec> odd,std::vector<t_vec> extra, int power);
		int FillArrayDeque(char **av);
		int MergeDeque();
		int InsertDeque(int power);
		int SortDeque(std::deque<t_deque> main, std::deque<t_deque> pend,std::deque<t_deque> odd,std::deque<t_deque> extra, int power);
};

std::string giveLabel(int i);
int TestArgumentsVec(std::string str, std::vector<int> vec);
int nextJacobsthal(int prev, int prevPrev);
int findMatchInMainVec(const std::vector<t_vec>& main, const std::string& bLabel);
void printVectorVec(const std::vector<t_vec>& vec, const std::string& name);
void PushToVectorVec(std::vector<t_vec>& main, std::vector<int>& vec);
void BinarySearchSortVec(std::vector<t_vec>& main, std::vector<t_vec>& vector, int end);
int recursion2Vec(std::vector<t_vec>& main, std::vector<t_vec>& vector, int index, int start, int end);

int TestArgumentsDeque(std::string str, std::deque<int> vec);
int nextJacobsthal(int prev, int prevPrev);
int findMatchInMainDeque(const std::deque<t_deque>& main, const std::string& bLabel);
void printVectorDeque(const std::deque<t_deque>& vec, const std::string& name);
void PushToVectorDeque(std::deque<t_deque>& main, std::deque<int>& vec);
void BinarySearchSortDeque(std::deque<t_deque>& main, std::deque<t_deque>& vector, int end);
int recursion2Deque(std::deque<t_deque>& main, std::deque<t_deque>& vector, int index, int start, int end);


#endif