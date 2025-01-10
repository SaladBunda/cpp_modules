/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:12:20 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/10 23:29:04 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): name("bunda"), sign_grade(100), exec_grade(50), is_signed(false)
{
	return ;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade): name(name), sign_grade(sign_grade), exec_grade(exec_grade), is_signed(false) 
{
	if(sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	else if(sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const & src): name(src.name), sign_grade(src.sign_grade), exec_grade(src.exec_grade), is_signed(src.is_signed)
{
	return ;
}

AForm const & AForm::operator=(AForm const & src)
{
	if(this == &src)
		return *this;
	else
	{
		this->is_signed = src.is_signed;
	}
	return *this;
}

AForm::~AForm(void)
{
	return ;
}

int AForm::getSignGrade(void) const
{
	return this->sign_grade;
}

int AForm::getExecGrade(void) const
{
	return this->exec_grade;
}

std::string AForm::getName(void) const
{
	return this->name;
}

bool AForm::getSignStatus(void) const
{
	return this->is_signed;
}

void AForm::beSigned(Bureaucrat const & crat)
{
	
	if(crat.getGrade() > this->sign_grade)
		throw GradeTooLowException();
	else
		this->is_signed = true;
}

std::ostream &operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << ", signing grade " << form.getSignGrade() << " and executing grade " << form.getExecGrade() << " signed status: " << form.getSignStatus() ;
	return os;
}
