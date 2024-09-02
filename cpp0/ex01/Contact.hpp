/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:40:18 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/09/02 16:06:04 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "main.hpp"

class Contact
{
    public:
    Contact(void);
    ~Contact(void);
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string number;
    std::string darkest_secret;
};



#endif