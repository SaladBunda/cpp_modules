/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:26:21 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/10/27 20:37:58 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void ll()
{
    system("leaks brain");
}

int main()
{
    //atexit(ll);
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Animal *animals = new Animal[100];
    
    //delete j;//should not create a leak
    //delete i;
    i->makeSound();
    j->makeSound();
    delete i;
    delete j;
    return 0;
}