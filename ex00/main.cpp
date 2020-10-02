/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 15:43:04 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/02 11:43:49 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

#include <sstream>
#include <string>
#include <iostream>


int	main(int argc, char* argv[]) {

	if (argc != 2) {
		std::cerr << "Usage : ./convert <value>" << std::endl;
		return 1;
	}


	std::string const	value(argv[1]);
	std::stringstream	ss;

	// If float
	if (value == "nanf" || value.substr(1) == "inff" || (value.find('.') != std::string::npos && *(value.rbegin()) == 'f')) {
		float	f;
		ss << value.substr(0, value.size() - 1);
		ss >> f;

		print_char(f);
		print_int(f);
		print_float(f);
		print_double(f);
	}

	// If double
	else if (value == "nan" || value.substr(1) == "inf" || value.find('.') != std::string::npos) {
		double	d;
		ss << value;
		ss >> d;

		print_char(d);
		print_int(d);
		print_float(d);
		print_double(d);
	}

	// If char
	else if (value.size() == 1 and !isdigit(value[0])) {
		char	c;
		ss << value;
		ss >> c;

		print_char(c);
		print_int(c);
		print_float(c);
		print_double(c);
	}

	// If nothing else, int
	else {
		int	i;
		ss << value;
		ss >> i;

		print_char(i);
		print_int(i);
		print_float(i);
		print_double(i);
	}


	return 0;
}
