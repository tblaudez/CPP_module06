/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaudez <tblaudez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 14:08:09 by tblaudez      #+#    #+#                 */
/*   Updated: 2020/10/09 15:41:46 by tblaudez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> // srand, rand
#include <ctime> // time
#include <iostream> // cout

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};


Base*	generate() {

	switch (rand() % 3) {
		case 0:
			return dynamic_cast<Base*>(new A);

		case 1:
			return dynamic_cast<Base*>(new B);

		case 2:
			return dynamic_cast<Base*>(new C);

		default:
			return NULL;
	}


}

void identify_from_reference(Base& p) {

	try
	{
		A a_class = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast& e) {
		// Do nothing
	}

	try
	{
		B b_class = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast& e) {
		// Do nothing
	}

	try
	{
		C c_class = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast& e) {
		// Do nothing
	}
}

void identify_from_pointer(Base* p) {

	A* a_class = dynamic_cast<A*>(p);
	if (a_class != NULL) {
		std::cout << "A" << std::endl;
		return;
	}

	B* b_class = dynamic_cast<B*>(p);
	if (b_class != NULL) {
		std::cout << "B" << std::endl;
		return;
	}

	C* c_class = dynamic_cast<C*>(p);
	if (c_class != NULL) {
		std::cout << "C" << std::endl;
		return;
	}
}

int	main(void) {

	srand(time(0));

	Base* base = generate();

	identify_from_pointer(base);
	identify_from_reference(*base);

	delete  base;

	return 0;
}
