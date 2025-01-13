/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:10:16 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/13 14:40:24 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(Intern const & src)
{
	return ;
}

Intern const & Intern::operator=(Intern const & src)
{
	return *this;
}


Intern::~Intern(void)
{
	return ;
}

Form* Intern::createPresident(std::string target)
{
	Form *form = new PresidentialPardonForm(target);
	return form;
}

Form* Intern::createShrub(std::string target)
{
	Form *form = new ShrubberyCreationForm(target);
	return form;
}

Form* Intern::createRobot(std::string target)
{
	Form *form = new RobotomyRequestForm(target);
	return form;
}

Form* Intern::makeForm(std::string name, std::string target)
{
	Intern obj;
    Form* (Intern::*pointer[])(std::string)={&Intern::createPresident, &Intern::createShrub,&Intern::createRobot};
    std::string option[] = {"Presidential pardon","Shrubbery form","Robotomy form"};
    int i = 0;
    while(name != option[i] && i<4)
        i++;
    (obj.*pointer[i])(target);
}