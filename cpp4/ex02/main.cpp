/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:26:21 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/30 21:33:45 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void ll()
{
    system("leaks brain");
}

int main()
{
    atexit(ll);
    //const AAnimal* j = new Dog();
    //const AAnimal* i = new Cat();
    AAnimal **AAnimals = new AAnimal*[100];
    for (int i = 0; i < 50; i++)
    {
        AAnimals[i] = new Dog();
        AAnimals[i + 50] = new Cat();
    }
    for (int i = 0; i < 100; i++)
    {
        AAnimals[i]->makeSound();
    }
    for(int i = 0; i < 100; i++)
    {
        delete AAnimals[i];
    }
    delete[] AAnimals;
    //delete j;//should not create a leak
    //delete i;
    //i->makeSound();
    //j->makeSound();
    //delete i;
    //delete j;
    return 0;
}