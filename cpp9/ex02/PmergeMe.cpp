/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:21:54 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/17 21:53:25 by ael-maaz         ###   ########.fr       */
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
void printVector(const std::vector<std::vector<std::string> >& vec, const std::string& name) {
    std::cout << "Contents of " << name << ":\n";
    if (vec.empty()) {
        std::cout << "Empty\n";
        return;
    }
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "Group " << (i + 1) << ": ";
        for (size_t j = 0; j < vec[i].size(); ++j) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


int PmergeMe::Insert(int power)
{
	int num_of_pairs;
	power = 2;
	num_of_pairs = this->vec.size() / power;
	std::cout << num_of_pairs << std::endl;
	std::cout << power <<std::endl;
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
		for(std::vector<std::string>::iterator it = arr[i].vect.begin();it != arr[i].vect.end();it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		if(arr[i].vect.size() == static_cast<unsigned int>(power))
		{
			arr[i].info = FULL;
			num_of_fulls++;
		}
		else
			arr[i].info = NOT_FULL;
	}

	std::vector<std::vector <std::string> > main;
	std::vector<std::vector <std::string> > pend;
	std::vector<std::vector <std::string> > odd;
	std::vector<std::vector <std::string> > extra;
	
	for(int i = 0; i < num_of_pairs;i++)
	{
		if(arr[i].info == FULL)
		{
			if(num_of_fulls % 2 == 0)
			{
				if(i == 0 || i == 1 || i % 2 != 0)
					main.push_back(arr[i].vect);
				else if(i % 2 == 0)
					pend.push_back(arr[i].vect);		
			}
			else
			{
				if(i == 0 || i == 1)
					main.push_back(arr[i].vect);
				else if(i % 2 == 0 && i < num_of_fulls - 1)
					pend.push_back(arr[i].vect);
				else if(i % 2 != 0)
					main.push_back(arr[i].vect);
				else
					odd.push_back(arr[i].vect);
			}
				
		}
		else
			extra.push_back(arr[i].vect);
			
	}
	
	printVector(main, "main");
    printVector(pend, "pend");
    printVector(odd, "odd");
    printVector(extra, "extra");
	// if()
	return 1;
}