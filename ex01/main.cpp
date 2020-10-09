/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 11:57:03 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 15:41:37 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> // srand, rand
#include <ctime> // time
#include <iostream> // cout, string
#include <cstring> // memcpy

struct Data { std::string s1; int n; std::string s2; };

void*	serialize() {

	char*			data = new char[20]();
	char const* 	alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	for (int i=0; i < 8; i++) {
		data[i] = alphanum[rand() % 62];
		data[12+i] = alphanum[rand() % 62];
	}

	int n = rand();
	memcpy(data+8, &n, sizeof(n));

	std::cout << "Serialized bytes 1: " << std::cout.write(data, 8) << std::endl;
	std::cout << "Serialized integer: " << n << std::endl;
	std::cout << "Serialized bytes 2: "<< std::cout.write(data+12, 8) << std::endl;

	return reinterpret_cast<void*>(data);
}

Data*	deserialize(void* raw) {

	Data*	data = new Data;
	char*	raw_data = reinterpret_cast<char*>(raw);

	data->s1 = std::string(raw_data, 8);
	memcpy(&data->n, raw_data+8, sizeof(int));
	data->s2 = std::string(raw_data+12, 8);

	return data;
}

int	main(void) {

	srand(time(0));

	void* data = serialize();
	Data* clean_data = deserialize(data);

	std::cout << "Data->s1: " << clean_data->s1 << std::endl;
	std::cout << "Data->n: " << clean_data->n << std::endl;
	std::cout << "Data->s2: " << clean_data->s2 << std::endl;

	delete[] reinterpret_cast<char*>(data);
	delete clean_data;

	return 0;
}
