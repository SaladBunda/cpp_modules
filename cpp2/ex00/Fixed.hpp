/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:34:21 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 21:38:08 by ael-maaz         ###   ########.fr       */
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
        static const int fract = 8;
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed &copy);
        Fixed & operator=(Fixed & src);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};


#endif