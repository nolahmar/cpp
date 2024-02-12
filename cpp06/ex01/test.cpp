/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:10:36 by nolahmar          #+#    #+#             */
/*   Updated: 2024/02/12 14:31:23 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

using namespace std;

void to_binary(int a)
{
    for (int i = 31; i >= 0; --i)
    {
        if (a & (1 << i)) cout << 1 << " ";
        else cout << 0 << " ";
    }
    cout << endl;
}
int main()
{
    int a = 1000;
    to_binary(a);
    int *p = &a;
    char *s = (char*)&a;
    int *k = (int*)s;
    cout << "p = " << *p << endl;
    // cout << "s = " << *s << endl;
    printf("%d\n", *s);
    cout << "k = " << *k << endl;
    // float p = 3.14f;
    // std::cout << (int)(p) << std::endl;
    // int *s = reinterpret_cast<int *>(&p);
    // printf("s = %p\np = %p\n", s, &p);
    // std::cout << *reinterpret_cast<int *>(&p) << std::endl;
    // std::cout << *reinterpret_cast<float *>(&p) << std::endl;
}