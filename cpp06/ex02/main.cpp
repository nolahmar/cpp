/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:20:51 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/13 13:18:10 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
class Base {
    public:
        virtual ~Base();
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base::~Base() {
    
}

Base* generate(void) {
    int random = rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return 0;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type: C " << std::endl;
}

void identify(Base &p) {
     try {
        Base a = dynamic_cast<A&>(p);
        std::cout << "Type: A" << std::endl;
    }
    catch (const std::bad_cast&) {
    }

    try {
        Base b = dynamic_cast<B&>(p);
        std::cout << "Type: B" << std::endl;
    } catch (const std::bad_cast&) {
    }

    try {
        Base c = dynamic_cast<C&>(p);
        std::cout << "Type: C" << std::endl;
    } catch (const std::bad_cast&) {
    }
}

int main() {
  Base* object = generate();
    identify(object);
    delete object;
    return 0; 
}
