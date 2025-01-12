/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:12:20 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/10 23:15:20 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):AForm("PresidentialPardonForm",25,5), target("default")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm",25,5), target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm("PresidentialPardonForm",25,5)
{
	this->is_signed = src.is_signed;
	this->target = src.target;
	return ;
}

PresidentialPardonForm const & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
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

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(this->is_signed == false)
		throw FormNotSigned();
	else if(executor.getGrade() > this->exec_grade)
		throw GradeTooLowException();
	else
	{
		std::cout << this->target <<" has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}
