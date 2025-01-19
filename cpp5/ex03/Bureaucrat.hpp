/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:49:53 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/19 22:40:40 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>


#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
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

		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);
		int getGrade(void) const;
		std::string getName(void) const;
		void Inc(void);
		void Dec(void);
		Bureaucrat const & operator=(Bureaucrat const & src);
		void signForm(Form& form);
		void executeForm(Form const & form);
};


std::ostream &operator<<(std::ostream& os, const Bureaucrat& crat);

#endif