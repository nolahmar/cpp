/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:41:21 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/12 17:28:51 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data* data = new Data;
    Serializer s;

    data->name = "nouha";
    data->age = 20;

    uintptr_t serializedData = s.serialize(data);
    std::cout << "Serialized Data: " << serializedData << std::endl;
    Data* deserializedData = s.deserialize(serializedData);
    std::cout << "Deserialized Data: Name " << deserializedData->name
              << ", Age " << deserializedData->age << std::endl;
    delete data;

    return 0;
}

