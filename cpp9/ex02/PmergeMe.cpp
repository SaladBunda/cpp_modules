/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:21:54 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/24 23:25:29 by ael-maaz         ###   ########.fr       */
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
	std::cout << "Starting elements: ";
	for(unsigned int i = 0; i < this->vec.size();i++)
	{
			std::cout << this->vec[i]<< " " ;
	}
	std::cout << std::endl;
	int num_of_pairs;
	int power = 1;
	num_of_pairs = this->vec.size() / power;
	while(num_of_pairs > 1)
	{
		if(this->vec.size()%power != 0)
			num_of_pairs++;
		std::vector<std::string> arr[num_of_pairs];
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
		power *= 2;
        num_of_pairs = this->vec.size() / power;
	}
	return power;
}

int PmergeMe::Sort(std::vector<t_help> main, std::vector<t_help> pend,std::vector<t_help> odd,std::vector<t_help> extra, int power)
{
	unsigned int i = pend.size();
	int prevjacob = 1;
	int currentjacob  = 3;
	int tmp;

				// std::cout << "1\n"; 
	
				
				// printVector(pend,"pend");
				// printVector(pend,"odd");
				// printVector(pend,"extra");
				printVector(main,"main");
				
				printVector(pend,"pend");
				printVector(odd,"odd");
				printVector(extra,"extra");
	while(i > 0)
	{
		if(i < static_cast<unsigned int>(currentjacob - prevjacob))
		{
			// int swapped = 0;
			// unsigned int k = 0;
			while(pend.size() > 0)
			{
				// for(k = 0;k < main.size();k++)
				// {
				// 	// std::cout <<"pend element: "<<pend.back().vect.back().c_str()<<" with labbel: "<<pend.back().label<<std::endl;
				// 	if(std::atoi(pend.back().vect.back().c_str()) < std::atoi(main[k].vect.back().c_str()))
				// 	{
				// 		main.insert(main.begin() + k,pend.back());
				// 		pend.pop_back();
				// 		swapped = 1;
				// 		break;
				// 	}
				// }
				// if(swapped == 0)
				// {
				// 	main.insert(main.begin() + k,pend.back());
				// 	pend.pop_back();
				// }
				
				BinarySearchSort(main,pend);
			

			}
			if(!odd.empty())
			{
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
				
				BinarySearchSort(main,odd);
				

			}
		}
		else
		{
			for(int j = currentjacob - prevjacob;j > 0 ;j--)
			{
				int working_index = j - 1;
				std::string match = pend[working_index].label;
				int matched_index = findMatchInMain(main,match); 
				int swapped = 0;
				int k = 0;
				for(k = 0;k < matched_index;k++)
				{
					if(std::atoi(pend[working_index].vect.back().c_str()) < std::atoi(main[k].vect.back().c_str()))
					{
						main.insert(main.begin() + k,pend[working_index]);
						pend.erase(pend.begin() + working_index);
						swapped = 1;
						break ;
					}
				}
				if(swapped == 0)
				{
					main.insert(main.begin() + k,pend[working_index]);
						pend.erase(pend.begin() + working_index);
				}
			}
		}
		i = pend.size();
		tmp = prevjacob;
		prevjacob = currentjacob;
		currentjacob = nextJacobsthal(currentjacob,tmp);
	}

	if(!odd.empty())
	{
		// unsigned int k;
		// int swapped = 0;
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
		
		BinarySearchSort(main,odd);
		
	}
	if(!extra.empty())
	{
		if(power == 1)
		{
				
			BinarySearchSort(main,extra);
			
			// int swapped = 0;
			// unsigned int k = 0;
			// for(k = 0;k < main.size();k++)
			// {
			// 	if(std::atoi(extra.back().vect.back().c_str()) < std::atoi(main[k].vect.back().c_str()))
			// 	{
			// 		main.insert(main.begin() + k,extra.back());
			// 		extra.pop_back();
			// 		swapped = 1;
			// 		break;
			// 	}
			// }
			// if(swapped == 0)
			// {
			// 	main.insert(main.begin() + k,extra.back());
			// 	extra.pop_back();
			// }
			
		}
		else
		{
			main.push_back(extra.back());
			extra.pop_back();	
		}
	}
	PushToVector(main,this->vec);
	return 1;
}

int PmergeMe::Insert(int power)
{
	int num_of_pairs;
	while(power >= 1)
	{
		num_of_pairs = this->vec.size() / power;
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

		this->Sort(main,pend,odd,extra, power);
		power /= 2;
	}
	return 1;
}