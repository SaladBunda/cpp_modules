/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:08:11 by codespace         #+#    #+#             */
/*   Updated: 2024/09/12 18:27:25 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout <<Fixed(21)/0.5f<<std::endl;

Fixed number1(10.3f);
Fixed const number3(19.6654f);
Fixed const number4(19.8654f);
Fixed number2(10.4f);
std::cout << "Biggest:" <<a.max(number1,number2) << std::endl;
std::cout << "Smallest:" <<a.min(number3,number2) << std::endl;
std::cout << "Biggest:" <<a.max(number1,number4) << std::endl;
std::cout << "Smallest:" <<a.min(number3,number4) << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}