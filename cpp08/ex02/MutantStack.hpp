/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:15:06 by nolahmar          #+#    #+#             */
/*   Updated: 2024/03/01 16:44:44 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HBB
#define MUTANSTACK_HBB

#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>

template <typename T, typename Container = std::deque<T> >
class MutantStack:public std::stack<T, Container> {
    public:
        MutantStack(): std::stack<T, Container>() {};
        virtual ~MutantStack() {};
        MutantStack(const MutantStack& copy): std::stack<T, Container>(copy) {};
        // MutantStack& operator=(const MutantStack& copy) {
        // };

    typedef typename Container::iterator iterator;
    
    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }
    
    iterator cbegin() {
        return this->c.cbegin();
    }

    iterator cend() {
        return this->c.cend();
    }
    
};

#endif