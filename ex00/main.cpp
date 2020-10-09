/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 15:43:04 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 15:32:08 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

#include <sstream> // stringstream
#include <string> // duh..
#include <iostream> // cout, cerr
#include <cctype> // isdigit


int	main(int argc, char* argv[]) {

	if (argc != 2) {
		std::cerr << "Usage : ./convert <value>" << std::endl;
		return 1;
	}


	std::string const	value(argv[1]);
	std::stringstream	ss;

	std::cout << "----- \'" << value << "\' -----" << std::endl;

	// If float
	if (value == "nanf" || value == "+inff" || value == "-inff" || \
		(value.find('.') != std::string::npos && value[value.size() - 1] == 'f')) {

		float	f;
		// Get value without trailing 'f'
		ss << value.substr(0, value.size() - 1);
		// Get number of digits after '.'
		int const precision = value.substr(value.find('.') + 1).size();
		ss >> f;

		print_char(f);
		print_int(f);
		print_float(f, precision);
		print_double(f, precision);
	}

	// If double
	else if (value == "nan" || value == "+inf" || value == "-inf" || \
		value.find('.') != std::string::npos) {

		double	d;
		int const precision = value.substr(value.find('.') + 1).size();
		ss << value;
		ss >> d;

		print_char(d);
		print_int(d);
		print_float(d, precision);
		print_double(d, precision);
	}

	// If char
	else if (value.size() == 1 && !isdigit(value[0])) {
		char	c;
		ss << value;
		ss >> c;

		print_char(c);
		print_int(c);
		print_float(c, 1);
		print_double(c, 1);
	}

	// If nothing else, int
	else {
		int	i;
		ss << value;
		ss >> i;

		print_char(i);
		print_int(i);
		print_float(i, 1);
		print_double(i, 1);
	}

	return 0;
}
