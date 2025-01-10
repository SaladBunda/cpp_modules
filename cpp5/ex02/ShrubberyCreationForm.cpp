/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:12:20 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/10 23:40:16 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):AForm("ShrubberyCreationForm",145,137), target("default")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm",145,137), target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): AForm("ShrubberyCreationForm",145,137)
{
	this->is_signed = src.is_signed;
	this->target = src.target;
	return ;
}

ShrubberyCreationForm const & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	if(this == &src)
		return *this;
	else
	{
		this->target = src.target;
		this->is_signed = src.is_signed;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(this->is_signed == false)
		throw "Form not signed";
	else if(executor.getGrade() > this->exec_grade)
		throw GradeTooLowException();
	else
		std::ofstream outfile = ;
}

// std::ostream &operator<<(std::ostream& os, const ShrubberyCreationForm& form)
// {
// 	os << form.getName() << ", signing grade " << form.getSignGrade() << " and executing grade " << form.getExecGrade() << " signed status: " << form.getSignStatus() ;
// 	return os;
// }
