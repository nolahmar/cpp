/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:29:25 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/29 15:51:59 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	private:
		T* array;
		unsigned int n;
	public:
		Array():n(0) {
			array = new T[0];
		}
		
		Array(unsigned int n):n(n) {
			array = new T[n];
		}
    
		Array(Array const & src) : n(src.n) {
			//delete[] array;
			array = new T[n];
			for (unsigned int i = 0; i < n; i++)
				array[i] = src.array[i];
		}
		~Array() {
			delete[] array;
		}
        
		Array & operator=(Array const & other) {
			if (this != &other)
			{
				n = other.n;
				array = new T[n];
				for (unsigned int i = 0; i < n; i++)
					array[i] = other.array[i];
			}
		}
    
		T & operator[](unsigned int i) const {
			if (i > n) // if(i >= n)
				throw std::exception();
			return array[i];
		}
		
		unsigned int size() const {
			return n;
		}
};

#endif
