/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:12:20 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/10 23:27:29 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):AForm("RobotomyRequestForm",72,45), target("default")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm",72,45), target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): AForm("RobotomyRequestForm",72,45)
{
	this->is_signed = src.is_signed;
	this->target = src.target;
	return ;
}

RobotomyRequestForm const & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
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

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

// std::ostream &operator<<(std::ostream& os, const ShrubberyCreationForm& form)
// {
// 	os << form.getName() << ", signing grade " << form.getSignGrade() << " and executing grade " << form.getExecGrade() << " signed status: " << form.getSignStatus() ;
// 	return os;
// }
