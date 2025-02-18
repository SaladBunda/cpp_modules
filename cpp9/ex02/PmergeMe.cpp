/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:21:54 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/18 22:47:25 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	std::cout << "Default Constructor called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	if(this != &src)
	{
		this->vec = src.vec;
		this->que = src.que;
	}
	std::cout << "Copy constructor called" << std::endl;
}

PmergeMe const & PmergeMe::operator=(PmergeMe const & src)
{
	if(this != &src)
	{
		this->vec = src.vec;
		this->que = src.que;
	}
	return *this;	
}

PmergeMe::~PmergeMe(void)
{
	std::cout << "Destructor called" << std::endl;
}

int PmergeMe::FillArray(char **av)
{
	std::string word;
	for(int i = 1;av[i];i++)
	{
		
		std::stringstream s(av[i]);
		while(s >> word)
		{
			if(TestArguments(word,this->vec) == 1)
				return 1;
			this->vec.push_back(word);
		}
		
	}
	return 0;
}


int PmergeMe::Merge()
{
	for(unsigned int i = 0; i < this->vec.size();i++)
	{
			std::cout << this->vec[i]<< " " ;
	}
	std::cout << std::endl;
	int num_of_pairs;
	int power = 1;
	num_of_pairs = this->vec.size() / power;
	std::cout << num_of_pairs << std::endl;
	while(num_of_pairs > 1)
	{
		std::cout << "Power: "<< power << std::endl;
		if(this->vec.size()%power != 0)
			num_of_pairs++;
		std::vector<std::string> arr[num_of_pairs];
		// std::cout << "number of pairs: " << num_of_pairs<< std::endl;
		
		for(int i = 0;i < num_of_pairs;i++)
		{
			
			for(int j = 0;j < power;j++)
			{
				if(this->vec[power * i + j].length() > 0)
					arr[i].push_back(this->vec[power * i + j]) ;
			}
		}
		for(int i = 0;i < num_of_pairs;i++)
		{
			if(i + 1 < num_of_pairs)
			{
				if(std::atoi(arr[i].back().c_str()) > std::atoi(arr[i + 1].back().c_str()) && arr[i+1].size() == (unsigned int) power)
					std::swap(arr[i],arr[i+1]);
				i++;
			}
			else
				break;
		}
		this->vec.clear();
		for(int i = 0;i < num_of_pairs;i++)
		{
			for(std::vector<std::string>::iterator it = arr[i].begin();it != arr[i].end();it++)
			{
				if((*it).length() > 0)
					this->vec.push_back(*it);
				
			}
		}
		for(unsigned int i = 0; i < this->vec.size();i++)
		{
			std::cout << this->vec[i]<< " " ;
		}
		std::cout << std::endl;
		power *= 2;
        num_of_pairs = this->vec.size() / power;
	}
	return power;
}




// Function to print a vector of vector of strings (C++98 compatible)
void printVector(const std::vector<t_help>& vec, const std::string& name) {
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

int nextJacobsthal(int prev, int prevPrev)
{
    return prev + 2 * prevPrev;
}

int findMatchInMain(const std::vector<t_help>& main, const std::string& bLabel) {
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

// void findPairs(const std::vector<t_help>& pend) {
//     std::cout << "Found pairs:\n";
//     for (size_t i = 0; i < pend.size(); ++i) {
//         if (pend[i].label[0] == 'b') {
//             std::string pairLabel = 'a' + pend[i].label.substr(1);
//             for (size_t j = 0; j < pend.size(); ++j) {
//                 if (pend[j].label == pairLabel) {
//                     std::cout << "(" << pend[i].label << ", " << pend[j].label << ")\n";
//                 }
//             }
//         }
//     }
// }

int PmergeMe::Sort(std::vector<t_help> main, std::vector<t_help> pend,std::vector<t_help> odd,std::vector<t_help> extra)
{
	(void) main;
	(void) pend;
	(void) odd;
	(void) extra;
	
	unsigned int i = pend.size();
	int prevjacob = 1;
	int currentjacob  = 3;
	int tmp;
	if(pend.size() == 0)
	{
		this->vec.clear();
		for(unsigned int i = 0;i <main.size();i++)
		{
			for(std::vector<std::string>::iterator it = main[i].vect.begin();it != main[i].vect.end();it++)
			{
				if((*it).length() > 0)
					this->vec.push_back(*it);
				
			}
		}
		for(std::vector<std::string>::iterator it = extra[i].vect.begin();it != extra[i].vect.end();it++)
		{
				if((*it).length() > 0)
					this->vec.push_back(*it);
				
		}
		return 0;
	}
	while(i >= 0)
	{
		if(i < static_cast<unsigned int>(currentjacob - prevjacob))
		{
			//normal sort
			std::cout << "will work on this later" << std::endl;
						pend.pop_back();

			// i--;
			// continue;
		}
		else
		{
			for(int j = currentjacob - prevjacob;j >=0 ;j--)
			{
				int working_index = j - 1;
				std::cout << "index inside pend: " << working_index << std::endl;
				std::string match = pend[working_index].label;
				std::cout << "current jacob: " << currentjacob << " current element label: " << match <<std::endl;
				int matched_index = findMatchInMain(main,match); 
				std::cout << "found index in main: " <<matched_index << std::endl;
				int swapped = 0;
				int k = 0;
				for(k = 0;k < matched_index;k++)
				{
					if(std::atoi(pend[working_index].vect.back().c_str()) < std::atoi(main[k].vect.back().c_str()))
					{
						std::cout << "found bigger number we swap: " <<pend[working_index].vect.back() << " and "<< main[k].vect.back() << std::endl;
						main.insert(main.begin() + k,pend[working_index]);
						pend.erase(pend.begin() + working_index);
						swapped = 1;
					}
					// else
					// 	std::cout <<"impossible" << std::endl;
									
	
				}
				if(swapped == 0)
				{
					main.insert(main.begin() + k,pend[working_index]);
						pend.erase(pend.begin() + working_index);
					std::cout << "sawpped after loop" << std::endl;
				}
				// i--;
				std::cout << "TEST-----------" << std::endl;
				printVector(pend,"pend");
				printVector(main,"main");
				
			}
		}
		i = pend.size();
		tmp = prevjacob;
		prevjacob = currentjacob;
		currentjacob = nextJacobsthal(currentjacob,tmp);
	}
	return 1;
}

int PmergeMe::Insert(int power)
{
	int num_of_pairs;
	// power = 2;
	while(power >= 1)
	{
		num_of_pairs = this->vec.size() / power;
		std::cout << num_of_pairs << std::endl;
		std::cout << "Power: "<< power << std::endl;
		if(this->vec.size()%power != 0)
			num_of_pairs++;
		t_help arr[num_of_pairs];
		
		for(int i = 0;i < num_of_pairs;i++)
		{
			
			for(int j = 0;j < power;j++)
			{
				if(this->vec[power * i + j].length() > 0)
					arr[i].vect.push_back(this->vec[power * i + j]) ;
			}
		}

		int num_of_fulls = 0;
		for(int i = 0; i < num_of_pairs;i++)
		{
			if(arr[i].vect.size() == static_cast<unsigned int>(power))
			{
				arr[i].info = FULL;
				num_of_fulls++;
			}
			else
				arr[i].info = NOT_FULL;
		}

		std::vector<t_help> main;
		std::vector<t_help> pend;
		std::vector<t_help> odd;
		std::vector<t_help> extra;
		
		for(int i = 0; i < num_of_pairs;i++)
		{
			arr[i].label = giveLabel(i);
			if(arr[i].info == FULL)
			{
				if(num_of_fulls % 2 == 0)
				{
					if(i == 0 || i == 1 || i % 2 != 0)
					{
						main.push_back(arr[i]);
						
					}
					else if(i % 2 == 0)
						pend.push_back(arr[i]);		
				}
				else
				{
					if(i == 0 || i == 1)
						main.push_back(arr[i]);
					else if(i % 2 == 0 && i < num_of_fulls - 1)
						pend.push_back(arr[i]);
					else if(i % 2 != 0)
						main.push_back(arr[i]);
					else
						odd.push_back(arr[i]);
				}
			}
			else
				extra.push_back(arr[i]);
		}
		printVector(main,"main");
		printVector(pend,"pend");
		printVector(odd,"odd");
		printVector(extra,"extra");
		this->Sort(main,pend,odd,extra);
		
		power /= 2;
	}
	return 1;
}