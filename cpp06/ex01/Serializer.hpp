/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:41:24 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/27 17:27:20 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

struct Data {
    int age;
    std::string name;
};

class Serializer {
    public:
        Serializer();
        Serializer(Serializer const& x);
        Serializer& operator=(Serializer const& x);
        ~Serializer();

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);      
};

#endif