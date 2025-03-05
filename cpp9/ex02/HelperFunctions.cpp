/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:20:00 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/03/05 23:50:25 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int TestArgumentsVec(std::string str, std::vector<int> vec)
{
	(void) vec;
	long	num = std::atol(str.c_str());
	if(str.find_first_not_of("0123456789") != str.npos)
	{
		std::cout << "Found forbidden shit" << std::endl;
		return 1;
	}
	else if(num> INT_MAX)
	{
		std:: cout << "Numbers are supposed to be < MAX_INT\n";
		return 1;
	}

	return 0;		
}

std::string intToString(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}

std::string giveLabel(int i)
{
	int pairNumber = (i / 2) + 1;
	if(i % 2 ==0)
		return ("b" + intToString(pairNumber));
	else
		return("a" +  intToString(pairNumber));
}

int nextJacobsthal(int prev, int prevPrev)
{
    return prev + 2 * prevPrev;
}

int findMatchInMainVec(const std::vector<t_vec>& main, const std::string& bLabel)
{
    if (bLabel[0] != 'b') 
        return -1; 
    
    std::string aLabel = 'a' + bLabel.substr(1);

    for (size_t i = 0; i < main.size(); ++i) {
        if (main[i].label == aLabel) {
            return static_cast<int>(i);
        }
    }

    return -1; 
}

void printVectorVec(const std::vector<t_vec>& vec, const std::string& name)
{
    std::cout << "Contents of " << name << ":\n";
    if (vec.empty()) {
        std::cout << "Empty\n";
        return;
    }

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "Group " << (i + 1) << " (" << vec[i].label << "): ";
        for (size_t j = 0; j < vec[i].vect.size(); ++j) {
            std::cout << vec[i].vect[j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void PushToVectorVec(std::vector<t_vec>& main, std::vector<int>& vec)
{
	vec.clear();
	for(unsigned int i = 0;i <main.size();i++)
		{
			for(std::vector<int>::iterator it = main[i].vect.begin();it != main[i].vect.end();it++)
			{
					vec.push_back(*it);
			}
		}
}

int recursion(std::vector<t_vec>& main, std::vector<t_vec>& vector, int start, int end)
{
	int middle = (start + end)/2;
	if(start >= end)
	{
		if(vector.back().vect.back() > main[start].vect.back())
			main.insert(main.begin() + start + 1,vector.back());
		else
			main.insert(main.begin() + start,vector.back());
		vector.pop_back();
		return 1;
	}
	if(vector.back().vect.back() < main[middle].vect.back())
	{
		end = middle -1;
		recursion(main,vector,start,end);
	}
	else if(vector.back().vect.back() > main[middle].vect.back())
	{
		start = middle + 1;
		recursion(main,vector,start,end);
	}
	return 0;
}

void BinarySearchSortVec(std::vector<t_vec>& main, std::vector<t_vec>& vector, int end)
{
	int start = 0;
	recursion(main,vector,start,end);

}


int recursion2Vec(std::vector<t_vec>& main, std::vector<t_vec>& vector, int index, int start, int end)
{
	int middle = (start + end)/2;
	if(start >= end)
	{
		if(vector[index].vect.back() > main[start].vect.back())
			main.insert(main.begin() + start + 1,vector[index]);
		else
			main.insert(main.begin() + start,vector[index]);
		vector.erase(vector.begin() + index);
		return 1;
	}
	if(vector[index].vect.back() < main[middle].vect.back())
	{
		end = middle -1;
		recursion2Vec(main,vector,index,start,end);
	}
	else if(vector[index].vect.back() > main[middle].vect.back())
	{
		start = middle + 1;
		recursion2Vec(main,vector,index,start,end);
	}
	return 0;
}