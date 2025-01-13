/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:12:20 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/13 11:40:47 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):Form("ShrubberyCreationForm",145,137), target("default")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm",145,137), target(target)
{
	std::cout << "Shrubbery form created" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): Form("ShrubberyCreationForm",145,137)
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
		throw FormNotSigned();
	else if(executor.getGrade() > this->exec_grade)
		throw GradeTooLowException();
	else
	{
		std::string taget = this->target;
		const char *filename2 = (taget += "_shrubbery").c_str();
		std::ofstream outfile(filename2);
		if(outfile.is_open() == false)
       		throw "Failed to open file";
		outfile << "      /\\      " << std::endl;
        outfile << "     /\\*\\     " << std::endl;
        outfile << "    /\\O\\*\\    " << std::endl;
        outfile << "   /*/\\/\\/\\   " << std::endl;
        outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
        outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
        outfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
        outfile << "      ||      " << std::endl;
        outfile << "      ||      " << std::endl;
        outfile << "      ||      " << std::endl;
        outfile.close();

	}
}
