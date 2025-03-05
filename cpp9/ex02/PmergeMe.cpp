/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:21:54 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/03/05 23:56:44 by ael-maaz         ###   ########.fr       */
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

int PmergeMe::FillArrayVec(char **av)
{
	std::string word;
	for(int i = 1;av[i];i++)
	{
		
		// std::stringstream s(av[i]);
		// while(s >> word)
		// {
			// std::cout << "Word :-" << word << "-\n";
			word = av[i];
			if(TestArgumentsVec(word,this->vec) == 1)
				return 1;
			// if(word.length() > 0)
				this->vec.push_back(std::atoi(word.c_str()));
		// }
		
	}
	return 0;
}


int PmergeMe::MergeVec()
{
	int num_of_pairs;
	int power = 1;
	num_of_pairs = this->vec.size() / power;
	while(num_of_pairs > 1)
	{
		if(this->vec.size()%power != 0)
			num_of_pairs++;
		std::vector<int> arr[num_of_pairs];
		for(int i = 0;i < num_of_pairs;i++)
		{
			
			for(int j = 0;j < power;j++)
			{
				if(static_cast<size_t>(power *i + j) < this->vec.size())
					arr[i].push_back(this->vec[power * i + j]) ;
			}			
		}
		for(int i = 0;i < num_of_pairs;i++)
		{
			if(i + 1 < num_of_pairs)
			{
				if(arr[i].back() > arr[i + 1].back() && arr[i+1].size() == (unsigned int) power)
					std::swap(arr[i],arr[i+1]);
				i++;
			}
			else
				break;
		}
		this->vec.clear();
		for(int i = 0;i < num_of_pairs;i++)
		{
			for(std::vector<int>::iterator it = arr[i].begin();it != arr[i].end();it++)
					this->vec.push_back(*it);
		}
		power *= 2;
        num_of_pairs = this->vec.size() / power;
	}
	return power;
}

int PmergeMe::SortVec(std::vector<t_vec> main, std::vector<t_vec> pend,std::vector<t_vec> odd,std::vector<t_vec> extra, int power)
{
	// printVector(main,"main");
	// printVector(pend,"pend");
	// printVector(odd,"odd");
	// printVector(extra,"extra");
	
	unsigned int i = pend.size();
	int tmp = 0;
	int jacob[]={1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	int prevjacob = jacob[tmp++];
	int currentjacob  = jacob[tmp];
	
	while(i > 0)
	{
		// std::cout << "Size of Pend: " <<i << std::endl;
		// std::cout << currentjacob << " " << prevjacob << std::endl;
		if(i < static_cast<unsigned int>(currentjacob - prevjacob))
		{
			// std::cout << "no jacobsthall\n";
			while(pend.size() > 0)
			{
				std::string to_find = pend.back().label;
				int match = findMatchInMainVec(main,to_find);
				BinarySearchSortVec(main,pend, match);
			}
			if(!odd.empty())
				BinarySearchSortVec(main,odd,main.size() - 1);
		}
		else
		{
			// std::cout << "jacobsthall\n";

			for(int j = currentjacob - prevjacob;j > 0 ;j--)
			{
				// std::cout << "J: " << j << std::endl;
				// std::cerr << "Current jacob: " << currentjacob << std::endl;
				int working_index = j - 1;
				std::string match = pend[working_index].label;
				int matched_index = findMatchInMainVec(main,match); 
				// BinarySearchSortVec(main,pend, matched_index);
				// std::time_t a1 = std::clock();
				recursion2Vec(main,pend,working_index,0,matched_index);
				// std::time_t a2 = std::clock();
					// std::cout << "Duration of recursion to Vector: " <<static_cast<double>(a2- a1)/ CLOCKS_PER_SEC << std:: endl;

				
				// int swapped = 0;
				// int k = 0;
				// for(k = 0;k < matched_index;k++)
				// {
				// 	if(pend[working_index].vect.back() < main[k].vect.back())
				// 	{
				// 		main.insert(main.begin() + k,pend[working_index]);
				// 		pend.erase(pend.begin() + working_index);
				// 		swapped = 1;
				// 		break ;
				// 	}
				// }
				// if(swapped == 0)
				// {
				// 	main.insert(main.begin() + k,pend[working_index]);
				// 		pend.erase(pend.begin() + working_index);
				// }
			}
		}
		i = pend.size();
		// tmp = prevjacob;
		prevjacob = currentjacob;
		// std::cout << "tmp: " << tmp << std::endl; 
		currentjacob = jacob[++tmp];
		// std::cout <<jacob[tmp] <<" " << tmp << std::endl;
		// std::cout << currentjacob << std::endl;
		// std::cout << prevjacob << std::endl;
		// currentjacob = nextJacobsthal(currentjacob,tmp);
	}

	if(!odd.empty())
		BinarySearchSortVec(main,odd,main.size() - 1);
	if(!extra.empty())
	{
		if(power == 1)
			BinarySearchSortVec(main,extra,main.size() - 1);
		else
		{
			main.push_back(extra.back());
			extra.pop_back();	
		}
	}
	// std::time_t begin = std::clock();
	PushToVectorVec(main,this->vec);
	// std::time_t finish = std::clock();
	// std::cout << "Duration of push to Vector: " <<static_cast<double>(finish - begin)/ CLOCKS_PER_SEC << std:: endl;
	return 1;
}

int PmergeMe::InsertVec(int power)
{
	int num_of_pairs;
	while(power >= 1)
	{
		// std::time_t begin = std::clock();
		num_of_pairs = this->vec.size() / power;
		if(this->vec.size()%power != 0)
			num_of_pairs++;
		t_vec arr[num_of_pairs];
		
		for(int i = 0;i < num_of_pairs;i++)
		{
			
			for(int j = 0;j < power;j++)
			{
				if(static_cast<size_t>(power *i + j) < this->vec.size())
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

		std::vector<t_vec> main;
		std::vector<t_vec> pend;
		std::vector<t_vec> odd;
		std::vector<t_vec> extra;
		
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
		// std::time_t finish = std::clock();
		
		// std::cout << "Duration of labeling: " << double(finish - begin)/CLOCKS_PER_SEC << std::endl;
		this->start = std::clock();
		this->SortVec(main,pend,odd,extra, power);
		this->checkpoint = std::clock();
		// std::cout << "Duration of sort: " << double(this->checkpoint - this->start)/CLOCKS_PER_SEC << std::endl;
		power /= 2;
	}
	return 1;
}




int PmergeMe::FillArrayDeque(char **av)
{
	std::string word;
	for(int i = 1;av[i];i++)
	{
		
		// std::stringstream s(av[i]);
		// while(s >> word)
		// {
			// std::cout << "Word :-" << word << "-\n";
			word = av[i];
			if(TestArgumentsDeque(word,this->que) == 1)
				return 1;
			// if(word.length() > 0)
				this->que.push_back(std::atoi(word.c_str()));
		// }
		
	}
	return 0;
}


int PmergeMe::MergeDeque()
{
	int num_of_pairs;
	int power = 1;
	num_of_pairs = this->que.size() / power;
	while(num_of_pairs > 1)
	{
		if(this->que.size()%power != 0)
			num_of_pairs++;
		std::deque<int> arr[num_of_pairs];
		for(int i = 0;i < num_of_pairs;i++)
		{
			
			for(int j = 0;j < power;j++)
			{
				if(static_cast<size_t>(power *i + j) < this->que.size())
					arr[i].push_back(this->que[power * i + j]) ;
			}			
		}
		for(int i = 0;i < num_of_pairs;i++)
		{
			if(i + 1 < num_of_pairs)
			{
				if(arr[i].back() > arr[i + 1].back() && arr[i+1].size() == (unsigned int) power)
					std::swap(arr[i],arr[i+1]);
				i++;
			}
			else
				break;
		}
		this->que.clear();
		for(int i = 0;i < num_of_pairs;i++)
		{
			for(std::deque<int>::iterator it = arr[i].begin();it != arr[i].end();it++)
					this->que.push_back(*it);
		}
		power *= 2;
        num_of_pairs = this->que.size() / power;
	}
	return power;
}

int PmergeMe::SortDeque(std::deque<t_deque> main, std::deque<t_deque> pend,std::deque<t_deque> odd,std::deque<t_deque> extra, int power)
{
	// printVector(main,"main");
	// printVector(pend,"pend");
	// printVector(odd,"odd");
	// printVector(extra,"extra");
	
	unsigned int i = pend.size();
	int tmp = 0;
	int jacob[]={1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	int prevjacob = jacob[tmp++];
	int currentjacob  = jacob[tmp];
	
	while(i > 0)
	{
		// std::cout << "Size of Pend: " <<i << std::endl;
		// std::cout << currentjacob << " " << prevjacob << std::endl;
		if(i < static_cast<unsigned int>(currentjacob - prevjacob))
		{
			// std::cout << "no jacobsthall\n";
			while(pend.size() > 0)
			{
				std::string to_find = pend.back().label;
				int match = findMatchInMainDeque(main,to_find);
				BinarySearchSortDeque(main,pend, match);
			}
			if(!odd.empty())
				BinarySearchSortDeque(main,odd,main.size() - 1);
		}
		else
		{
			// std::cout << "jacobsthall\n";

			for(int j = currentjacob - prevjacob;j > 0 ;j--)
			{
				// std::cout << "J: " << j << std::endl;
				// std::cerr << "Current jacob: " << currentjacob << std::endl;
				int working_index = j - 1;
				std::string match = pend[working_index].label;
				int matched_index = findMatchInMainDeque(main,match); 
				// BinarySearchSortDeque(main,pend, matched_index);
				// std::time_t a1 = std::clock();
				recursion2Deque(main,pend,working_index,0,matched_index);
				// std::time_t a2 = std::clock();
					// std::cout << "Duration of recursion to Vector: " <<static_cast<double>(a2- a1)/ CLOCKS_PER_SEC << std:: endl;

				
				// int swapped = 0;
				// int k = 0;
				// for(k = 0;k < matched_index;k++)
				// {
				// 	if(pend[working_index].vect.back() < main[k].vect.back())
				// 	{
				// 		main.insert(main.begin() + k,pend[working_index]);
				// 		pend.erase(pend.begin() + working_index);
				// 		swapped = 1;
				// 		break ;
				// 	}
				// }
				// if(swapped == 0)
				// {
				// 	main.insert(main.begin() + k,pend[working_index]);
				// 		pend.erase(pend.begin() + working_index);
				// }
			}
		}
		i = pend.size();
		// tmp = prevjacob;
		prevjacob = currentjacob;
		// std::cout << "tmp: " << tmp << std::endl; 
		currentjacob = jacob[++tmp];
		// std::cout <<jacob[tmp] <<" " << tmp << std::endl;
		// std::cout << currentjacob << std::endl;
		// std::cout << prevjacob << std::endl;
		// currentjacob = nextJacobsthal(currentjacob,tmp);
	}

	if(!odd.empty())
		BinarySearchSortDeque(main,odd,main.size() - 1);
	if(!extra.empty())
	{
		if(power == 1)
			BinarySearchSortDeque(main,extra,main.size() - 1);
		else
		{
			main.push_back(extra.back());
			extra.pop_back();	
		}
	}
	// std::time_t begin = std::clock();
	PushToVectorDeque(main,this->que);
	// std::time_t finish = std::clock();
	// std::cout << "Duration of push to Vector: " <<static_cast<double>(finish - begin)/ CLOCKS_PER_SEC << std:: endl;
	return 1;
}

int PmergeMe::InsertDeque(int power)
{
	int num_of_pairs;
	while(power >= 1)
	{
		// std::time_t begin = std::clock();
		num_of_pairs = this->que.size() / power;
		if(this->que.size()%power != 0)
			num_of_pairs++;
		t_deque arr[num_of_pairs];
		
		for(int i = 0;i < num_of_pairs;i++)
		{
			
			for(int j = 0;j < power;j++)
			{
				if(static_cast<size_t>(power *i + j) < this->que.size())
					arr[i].vect.push_back(this->que[power * i + j]) ;
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

		std::deque<t_deque> main;
		std::deque<t_deque> pend;
		std::deque<t_deque> odd;
		std::deque<t_deque> extra;
		
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
		// std::time_t finish = std::clock();
		
		// std::cout << "Duration of labeling: " << double(finish - begin)/CLOCKS_PER_SEC << std::endl;
		this->start = std::clock();
		this->SortDeque(main,pend,odd,extra, power);
		this->checkpoint = std::clock();
		// std::cout << "Duration of sort: " << double(this->checkpoint - this->start)/CLOCKS_PER_SEC << std::endl;
		power /= 2;
	}
	return 1;
}