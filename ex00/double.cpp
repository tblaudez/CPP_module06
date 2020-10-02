/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:35:56 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/02 11:49:51 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>


void	print_double(double const& d) {

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
}

void	print_double(char const& c) {

	double d = static_cast<double>(c);
	print_double(d);
}

void	print_double(int const& i) {

	double d = static_cast<double>(i);
	print_double(d);
}

void	print_double(float const& f) {

	double d = static_cast<double>(f);
	print_double(d);
}
