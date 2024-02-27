/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:41:21 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/27 18:38:12 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data* data = new Data;

    data->name = "nouha";
    data->age = 20;

    uintptr_t serializedData = Serializer::serialize(data);
    Data* deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Deserialized Data: \nName: " << deserializedData->name
              << "\nAge: " << deserializedData->age << std::endl;
    delete data;
    return 0;
}
