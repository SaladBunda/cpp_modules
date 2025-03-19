/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:34:16 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/03/11 18:01:08 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool _check(std::vector<int>& vec, std::vector<int>& tmp) //!
{
    std::sort(tmp.begin(), tmp.end());
    if (vec.size() != tmp.size())
        return (false);
    for (size_t i = 0; i < tmp.size(); i++)
    {
        if (vec[i] != tmp[i]) {
			std::cout << vec[i] << "  " << tmp[i] << std::endl;
			std::cout << "NO********OOOT\n";
            return (false);
		}
    }
    return (true);
}

bool    isSorted(std::vector<int>& data) //!
{
    for (size_t i = 0; i < data.size() - 1; i++)
    {
        if (data[i] > data[i + 1]) {
			std::cout << "NOOOOOOOOOOOOOT\n";
            return (false);
		}
    }
    return (true);
}

int main(int ac, char **av)
{
	(void) ac;
	PmergeMe main;
	// std::time_t init = std::clock();
	std::time_t a1 = std::clock();
	main.start = std::clock();
	if(main.FillArrayVec(av) == 1)
		return 1;
	main.checkpoint = std::clock();
	std::vector<int> tmp;
	for (size_t i = 0; i < main.vec.size(); ++i)
		tmp.push_back(main.vec[i]);
	main.start = main.checkpoint;
	int power = main.MergeVec();
	main.checkpoint = std::clock();
main.start = main.checkpoint;
	main.InsertVec(power / 2);
	main.checkpoint = std::clock();
	std::time_t a2 = std::clock();
	
	std::cout << "End result: ";
	std::cout << "Duration of insertion: " << double(a2 - a1)/CLOCKS_PER_SEC << std::endl;	
	std::time_t b1 = std::clock();
	if(main.FillArrayDeque(av) == 1)
		return 1;
		int power2 = main.MergeDeque();
		main.InsertDeque(power2 /2);
	std::time_t b2 = std::clock();
	std::cout << "Duration of insertion of deque: " << double(b2 - b1)/CLOCKS_PER_SEC << std::endl;	
	
	// std::cout << "Array after fill: ";
	// std::cout << "Duration of parsing: " << double(main.checkpoint - main.start)/CLOCKS_PER_SEC << std::endl;	// std::cout << "Array after fill: ";
	// 	for(std::vector<int>::iterator it = main.vec.begin();it != main.vec.end();it++)
	// 	std::cout << *it << " "; 
	// std::cout << std::endl;
	// std::cout << "Duration of merging: " << double(main.checkpoint - main.start)/CLOCKS_PER_SEC << std::endl;	// std::cout << "Array after fill: ";

	// std::cout << "Start insertion result: ";
	// 	for(std::vector<int>::iterator it = main.vec.begin();it != main.vec.end();it++)
	// 	std::cout << *it << " "; 
	// std::cout << std::endl;
	// std::cout << "Duration of insertion: " << double(main.checkpoint - main.start)/CLOCKS_PER_SEC << std::endl;	// std::cout << "Array after fill: ";
	// for(std::vector<int>::iterator it = main.vec.begin();it != main.vec.end();it++)
	// 	std::cout << *it << " "; 
	// std::cout << std::endl;
	// std::time_t end = std::clock();
	// std::cout << "Time Elapsed: " <<double(end - init)/CLOCKS_PER_SEC  <<"s"<< std::endl;
	int zz = tmp.size();//!
	int ss = main.vec.size(); //!
	std::cout << "SS: " << ss << " ZZ: " << zz << std::endl;
	std::vector<int> tmp2;
	for (size_t i = 0; i < main.vec.size(); ++i)
		tmp2.push_back(main.vec[i]);
    if (isSorted(tmp2) && ss == zz && _check(tmp2, tmp))//!
        std::exit(0);//!
    else//!
        std::exit(1);//!
}