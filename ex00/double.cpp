/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:35:56 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 15:08:32 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip> // fixed, setprecision
#include <iostream> // cout


void	print_double(double const& d, int const& precison) {

	std::cout << std::fixed << std::setprecision(precison);
	std::cout << "double: " << d << std::endl;
}

void	print_double(char const& c, int const& precison) {

	double const d = static_cast<double const>(c);
	print_double(d, precison);
}

void	print_double(int const& i, int const& precison) {

	double const d = static_cast<double const>(i);
	print_double(d, precison);
}

void	print_double(float const& f, int const& precison) {

	double const d = static_cast<double const>(f);
	print_double(d, precison);
}
