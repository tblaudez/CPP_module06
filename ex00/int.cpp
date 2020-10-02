/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:32:01 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/02 11:47:58 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>


void	print_int(int const& i) {

	std::cout << "int: " << i << std::endl;
}

void	print_int(char const& c) {

	int	i = static_cast<char>(c);
	print_int(i);
}

void	print_int(double const& d) {

	if (isinf(d) || isnan(d)) {
		std::cout << "int: impossible" << std::endl;
	} else {
		int i = static_cast<int>(d);
		print_int(i);
	}
}

void	print_int(float const& f) {

	if (isinf(f) || isnan(f)) {
		std::cout << "int: impossible" << std::endl;
	} else {
		int i = static_cast<int>(f);
		print_int(i);
	}
}
