/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:20:00 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/24 23:24:21 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int TestArguments(std::string str, std::vector<std::string> vec)
{
	if(str.find_first_not_of("0123456789") != str.npos)
	{
		std::cout << "Found forbidden shit" << std::endl;
		return 1;
	}
	else
	{
		for(std::vector<std::string>::iterator it = vec.begin();it!=vec.end();it++)
		{
			if(*it == str)
			{
				std::cout << "duplicate" << std::endl;
				return 1;
			}
		}
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

int findMatchInMain(const std::vector<t_help>& main, const std::string& bLabel)
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

void printVector(const std::vector<t_help>& vec, const std::string& name)
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

void PushToVector(std::vector<t_help>& main, std::vector<std::string>& vec)
{
	vec.clear();
	for(unsigned int i = 0;i <main.size();i++)
		{
			for(std::vector<std::string>::iterator it = main[i].vect.begin();it != main[i].vect.end();it++)
			{
				if((*it).length() > 0)
					vec.push_back(*it);
				
			}
		}
}

#include <unistd.h>

int recursion(std::vector<t_help>& main, std::vector<t_help>& vector, int start, int end)
{
	int middle = (start + end)/2;
	// std::cout << "biggest Element: " << vector.back().vect.back() << std::endl;
	// std::cout << "biggest elements at main: " << main[middle].vect.back() << std::endl;
	// std::cout << "start: " << start << " end: " <<end << std::endl;
	if(start >= end)
	{
		// std::cout << "=Middle: " <<middle << std::endl;
		if(std::atoi(vector.back().vect.back().c_str()) > std::atoi(main[start].vect.back().c_str()))
			main.insert(main.begin() + start + 1,vector.back());
		else
			main.insert(main.begin() + start,vector.back());
		vector.pop_back();
		return 1;
	}
	if(std::atoi(vector.back().vect.back().c_str()) < std::atoi(main[middle].vect.back().c_str()))
	{
		// std::cout << "<Middle: " <<middle << std::endl;
		end = middle -1;
		// usleep(70000);
		recursion(main,vector,start,end);
	}
	else if(std::atoi(vector.back().vect.back().c_str()) > std::atoi(main[middle].vect.back().c_str()))
	{
		// std::cout << ">Middle: " <<middle << std::endl;
		start = middle + 1;
		// usleep(70000);
		recursion(main,vector,start,end);


	}

	return 0;
}

void BinarySearchSort(std::vector<t_help>& main, std::vector<t_help>& vector)
{
	int start = 0;
	int end = main.size() - 1;
	recursion(main,vector,start,end);
	// for(k = 0;k < main.size();k++)
	// {
	// 	if(std::atoi(odd.back().vect.back().c_str()) < std::atoi(main[k].vect.back().c_str()))
	// 	{
	// 		main.insert(main.begin() + k,odd.back());
	// 		odd.pop_back();
	// 		swapped = 1;
	// 		break;
	// 	}
	// }
	// if(swapped == 0)
	// {
	// 	main.insert(main.begin() + k,odd.back());
	// 	odd.pop_back();
	// }
}