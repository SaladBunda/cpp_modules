/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:16:20 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/12 22:42:48 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name("default"), grade(75)
{
	std::cout << "Bureaucrat " << this->name << "created with grade: " << this->grade << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{

	if(grade > 150)
		throw GradeTooLowException();
	else if(grade < 1)
		throw GradeTooHighException();
	else
	{
		this->grade = grade;
		std::cout << "Bureaucrat " << this->name << " created with grade: " << this->grade << std::endl;
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

	if(this->grade > 1)
	{
		this->grade--;
	}
	else
	{
		throw GradeTooHighException();
	}
	

}

void Bureaucrat::Dec()
{
	
	if(this->grade < 150)
		this->grade++;
	else
		throw GradeTooLowException();

}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& crat)
{
	os << crat.getName() << ", bureaucrat grade " << crat.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(AForm& form)
{
	if(this->grade > form.getSignGrade())
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because: ";
		throw GradeTooLowException();
	}
	else
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}