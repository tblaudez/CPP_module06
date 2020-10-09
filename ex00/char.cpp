/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:25:23 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 15:02:02 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cout
#include <cctype> // isprint


void	print_char(char const& c) {

	if (isprint(c)) {
		std::cout << "char: " << '\'' << c << '\'' << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void	print_char(int const& i) {

	char const c = static_cast<char const>(i);
	print_char(c);
}

void	print_char(double const& d) {

	// C99 macros
	if (isinf(d) || isnan(d)) {
		std::cout << "char: impossible" << std::endl;
	}
	else {
		char const c = static_cast<char const>(d);
		print_char(c);
	}
}

void	print_char(float const& f) {

	if (isinf(f) || isnan(f)) {
		std::cout << "char: impossible" << std::endl;
	}
	else {
		char const c = static_cast<char const>(f);
		print_char(c);
	}
}
