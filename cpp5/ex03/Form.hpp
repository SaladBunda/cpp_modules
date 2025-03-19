/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:49:14 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/13 11:38:34 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP


#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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
		class FormNotSigned : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("The form isnt signed");
				}
		};
		Form(void);
		Form(std::string name, int sign_grade, int exec_grade);
		Form(Form const & src);
		virtual ~Form(void);
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getSignStatus(void) const;
		std::string getName(void) const;
		Form const & operator=(Form const & src);
		void beSigned(Bureaucrat const & crat);
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream& os, const Form& form);


#endif