/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:38:59 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/02 11:50:09 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>


void	print_float(float const& f) {

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
}

void	print_float(double const& d) {

	float f = static_cast<float>(d);
	print_float(f);
}

void	print_float(char const& c) {

	float f = static_cast<float>(c);
	print_float(f);
}

void	print_float(int const& i) {

	float f = static_cast<float>(i);
	print_float(f);
}
