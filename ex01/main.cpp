/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:57:03 by tblaudez      #+#    #+#                 */
/*   Updated: 2021/01/21 17:45:19 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> // srand, rand
#include <ctime> // time
#include <iostream> // cout, string
#include <cstring> // memcpy

struct Data { std::string s1; int n; std::string s2; };

void*	serialize() {

	const char	alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	const int	n = arc4random();
	char*		data = new char[2 * sizeof(std::string) + sizeof(int)]();
	std::string	s1, s2;


	for (int i=0; i < 8; i++) {
		s1 += alphanum[arc4random_uniform(sizeof(alphanum))];
		s2 += alphanum[arc4random_uniform(sizeof(alphanum))];
	}

	memcpy(data, &s1, sizeof(s1));
	memcpy(data + sizeof(s1), &n, sizeof(n));
	memcpy(data + sizeof(s1) + sizeof(n), &s2, sizeof(s2));


	std::cout << "Serialized bytes 1: " << s1 << std::endl;
	std::cout << "Serialized integer: " << n << std::endl;
	std::cout << "Serialized bytes 2: "<< s2 << std::endl;

	return data;
}

Data*	deserialize(void* raw) {

	Data*	data = new Data();
	char*	raw_data = reinterpret_cast<char*>(raw);

	data->s1 = *reinterpret_cast<std::string*>(raw_data);
	data->n = *reinterpret_cast<int*>(raw_data + sizeof(std::string));
	data->s2 = *reinterpret_cast<std::string*>(raw_data + sizeof(std::string) + sizeof(int));

	return data;
}

int	main(void) {

	void*	data = serialize();
	Data*	clean_data = deserialize(data);

	std::cout << "Data->s1: " << clean_data->s1 << std::endl;
	std::cout << "Data->n: " << clean_data->n << std::endl;
	std::cout << "Data->s2: " << clean_data->s2 << std::endl;

	delete[] reinterpret_cast<char*>(data);
	delete clean_data;

	return 0;
}
