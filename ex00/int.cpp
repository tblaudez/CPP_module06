/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:32:01 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 15:11:07 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cout


void	print_int(int const& i) {

	std::cout << "int: " << i << std::endl;
}

void	print_int(char const& c) {

	int const	i = static_cast<int const>(c);
	print_int(i);
}

void	print_int(double const& d) {

	// C99 macros
	if (isinf(d) || isnan(d)) {
		std::cout << "int: impossible" << std::endl;
	} else {
		int const i = static_cast<int const>(d);
		print_int(i);
	}
}

void	print_int(float const& f) {

	// C99 macros
	if (isinf(f) || isnan(f)) {
		std::cout << "int: impossible" << std::endl;
	} else {
		int const i = static_cast<int const>(f);
		print_int(i);
	}
}
