/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:41:44 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 15:12:23 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

void	print_double(double const& d, int const& precision);
void	print_double(char const& c, int const& precision);
void	print_double(int const& i, int const& precision);
void	print_double(float const& f, int const& precision);

void	print_float(double const& d, int const& precision);
void	print_float(char const& c, int const& precision);
void	print_float(int const& i, int const& precision);
void	print_float(float const& f, int const& precision);

void	print_int(int const& i);
void	print_int(char const& c);
void	print_int(double const& f);
void	print_int(float const& f);

void	print_char(char const& c);
void	print_char(int const& i);
void	print_char(double const& d);
void	print_char(float const& f);
