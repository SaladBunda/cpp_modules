/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:12:20 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/09 22:25:24 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): name("bunda"), sign_grade(100), exec_grade(50), is_signed(false)
{
	return ;
}

Form::Form(std::string name, int sign_grade, int exec_grade, bool is_signed): name(name), sign_grade(sign_grade), exec_grade(exec_grade), is_signed(is_signed) 
{
	if(sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	else if(sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(Form const & src): name(src.name), sign_grade(src.sign_grade), exec_grade(src.exec_grade), is_signed(src.is_signed)
{
	return ;
}

Form const & Form::operator=(Form const & src)
{
	if(this == &src)
		return *this;
	else
	{
		this->is_signed = src.is_signed;
	}
	return *this;
}

Form::~Form(void)
{
	return ;
}

int Form::getSignGrade(void) const
{
	return this->sign_grade;
}

int Form::getExecGrade(void) const
{
	return this->exec_grade;
}

std::string Form::getName(void) const
{
	return this->name;
}

bool Form::getSignStatus(void) const
{
	return this->is_signed;
}

void Form::beSigned(Bureaucrat const & crat)
{
	try
	{
		if(crat.getGrade() > this->sign_grade)
			throw GradeTooLowException();
		else
			this->is_signed = true;
	}
	catch(GradeTooLowException e)
	{
		std::cout << e.TooLow() << std::endl;
	}
}

std::ostream &operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << ", signing grade " << form.getSignGrade() << " and executing grade " << form.getExecGrade() << " signed status: " << form.getSignStatus() ;
	return os;
}
