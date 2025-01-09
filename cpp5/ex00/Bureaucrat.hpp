/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:49:53 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/09 20:44:00 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>






class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* TooHigh() const throw()
				{
					return ("Grade is too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* TooLow() const throw()
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
		
};


std::ostream &operator<<(std::ostream& os, const Bureaucrat& crat);

#endif