/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:34:21 by codespace         #+#    #+#             */
/*   Updated: 2024/09/10 22:48:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int decimal;
        static const int fract = 4;
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(Fixed &copy);
        Fixed & operator=(Fixed & src);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};


#endif