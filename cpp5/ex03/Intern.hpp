/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:58:23 by ael-maaz          #+#    #+#             */
/*   Updated: 2025/01/13 14:29:26 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP


#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & src);
		Intern const & operator=(Intern const & src);
		~Intern(void);
		Form* makeForm(std::string name, std::string target);
		Form* createShrub(std::string target);	
		Form* createRobot(std::string target);	
		Form *createPresident(std::string target);	
};

#endif