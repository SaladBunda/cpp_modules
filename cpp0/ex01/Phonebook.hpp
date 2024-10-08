/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:39:22 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/05 19:21:40 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

class Phonebook 
{
    public:
    Phonebook(void);
    ~Phonebook(void);
    void add_contact(void);
    void search_contact(void);
    private:
    Contact contacts[8];
    int num;
    int current;
    
    
};



#endif