/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:16:20 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/09 22:32:40 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name("default"), grade(75)
{
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	try
	{
		if(grade > 150)
			throw GradeTooLowException();
		else if(grade < 1)
			throw GradeTooHighException();
		else
			this->grade = grade;
	}
	catch(GradeTooHighException e)
	{
		std::cout << e.TooHigh() << std::endl;
	}
	catch(GradeTooLowException e)
	{
		std::cout << e.TooLow() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	return ;
}


Bureaucrat::Bureaucrat(Bureaucrat const &src):  name(src.name), grade(src.grade)
{
	return ;
}


Bureaucrat const & Bureaucrat::operator=(Bureaucrat const & src)
{
	if(this == &src)
		return *this;
	else
	{
		this->grade = src.grade;
	}
	return *this;
}

int Bureaucrat::getGrade(void) const
{
	return this->grade;
}

std::string Bureaucrat::getName(void) const
{
	return this->name;
}

void Bureaucrat::Inc()
{
	try
	{
		if(this->grade > 1)
		{
			this->grade--;
			std::cout << "Here" << std::endl;
		}
		else
		{
			std::cout << "else" << std::endl;
			throw GradeTooHighException();
		}
	}
	catch(GradeTooHighException e)
	{
		std::cout << "test" << std::endl;
		std::cout << e.TooHigh() << std::endl;
	}
}

void Bureaucrat::Dec()
{
	try
	{
		if(this->grade < 150)
			this->grade++;
		else
			throw GradeTooLowException();
	}
	catch(GradeTooLowException e)
	{
		std::cout << e.TooLow() << std::endl;
	}
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& crat)
{
	os << crat.getName() << ", bureaucrat grade " << crat.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(Form & form)
{
	
	try
	{
		if(this->grade > form.getSignGrade())
			throw GradeTooLowException();
		else
			form.beSigned(*this);
	}
	catch(GradeTooLowException e)
	{
		std::cout << e.TooLow() << std::endl;
	}
}