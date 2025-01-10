/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:49:14 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/10 23:37:13 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP


#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string name;
		const int sign_grade;
		const int exec_grade;
		bool is_signed;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade is too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade is too Low");
				}
		};
		AForm(void);
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(AForm const & src);
		~AForm(void);
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getSignStatus(void) const;
		std::string getName(void) const;
		AForm const & operator=(AForm const & src);
		void beSigned(Bureaucrat const & crat);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream& os, const AForm& form);


#endif