/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:12:20 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/13 11:50:39 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):Form("RobotomyRequestForm",72,45), target("default")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm",72,45), target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): Form("RobotomyRequestForm",72,45)
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(this->is_signed == false)
		throw FormNotSigned();
	else if(executor.getGrade() > this->exec_grade)
		throw GradeTooLowException();
	else
	{
		std::cout << "Drilling noises..." << std::endl;
		std::srand(std::time(nullptr));
        int success = std::rand() % 2; 

        if (success) 
            std::cout << this->target << " has been robotomized successfully!" << std::endl;
        else 
            std::cout << "The robotomy of " << this->target << " failed!" << std::endl;
	}
}

