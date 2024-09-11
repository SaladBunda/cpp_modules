/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:34:21 by codespace         #+#    #+#             */
/*   Updated: 2024/09/10 22:49:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int decimal;
        static const int fract = 8;
    public:
        Fixed(void);
        Fixed(int const integer);
        Fixed(float const fl);
        Fixed(Fixed const &copy);
        ~Fixed(void);
        Fixed & operator=(Fixed const & src);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);


#endif