/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:17:32 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/25 15:25:16 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"


Base::~Base(void)
{
	return ;
}

Base * generate(void)
{
	std::srand(std::time(nullptr));
    int choice = std::rand() % 3;
	if(choice == 0)
	{
		A *cls = new A();;
		return cls;
	}else if(choice == 1)
	{
		B *cls = new B();;
		return cls;
	}
	else
	{
		C *cls = new C();;
		return cls;
	}
	// return NULL;
}
void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if(a)
		std::cout << "A" << std::endl;
	else
	{
		B* b = dynamic_cast<B*>(p);
		if(b)
			std::cout << "B" << std::endl;
		else
		{
			C* c = dynamic_cast<C*>(p);
			if(c)
				std::cout << "C" << std::endl;
			else
				std::cout << "UNKNOWN" << std::endl;
 		}
	}
}


void identify(Base& p)
{
	try{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
			(void) a;
		
	}catch(std::bad_cast &bc)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void) b;
		}
		catch(std::bad_cast &bc)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				(void) c;
			}
			catch(std::bad_cast &bc)
			{
				std::cout << bc.what() << std::endl;
			}
		}
	}
	
}