/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:34:16 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/02/24 22:20:47 by ael-maaz         ###   ########.fr       */
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
	// std::time_t start = std::clock();
	(void) ac;
	PmergeMe main;
	if(main.FillArray(av) == 1)
		return 1;
	std::vector<int> tmp;
	for (size_t i = 0; i < main.vec.size(); ++i)
		tmp.push_back(std::atoi(main.vec[i].c_str()));
	
	int power = main.Merge();
	std::cout << "Start insertion result: ";
		for(std::vector<std::string>::iterator it = main.vec.begin();it != main.vec.end();it++)
		std::cout << *it << " "; 
	std::cout << std::endl;

	main.Insert(power / 2);
	std::cout << "End result: ";
	for(std::vector<std::string>::iterator it = main.vec.begin();it != main.vec.end();it++)
		std::cout << *it << " "; 
	std::cout << std::endl;
	// std::time_t end = std::clock();
	// std::cout << "Time Elapsed: " <<double(end - start)/CLOCKS_PER_SEC * 1000 * 100 <<"us"<< std::endl;
	int zz = tmp.size();//!
	int ss = main.vec.size(); //!
	std::cout << "SS: " << ss << " ZZ: " << zz << std::endl;
	std::vector<int> tmp2;
	for (size_t i = 0; i < main.vec.size(); ++i)
		tmp2.push_back(std::atoi(main.vec[i].c_str()));
    if (isSorted(tmp2) && ss == zz && _check(tmp2, tmp))//!
        std::exit(0);//!
    else//!
        std::exit(1);//!
}