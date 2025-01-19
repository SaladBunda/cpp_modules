/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:53:35 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/19 23:12:13 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern(void);
		class InvalidForm : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return("Invalid Form\nChoose either:\n1-Presidential pardon\n2-Shrubbery form\n3-Robotomy form");
				}
		};
		Intern(Intern const & src);
		Intern const & operator=(Intern const & src);
		~Intern(void);
		Form* createPresident(std::string target);
		Form* createShrub(std::string target);
		Form* createRobot(std::string target);
		Form* makeForm(std::string name, std::string target);

};


#endif