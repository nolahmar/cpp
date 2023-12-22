/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:21:43 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/22 15:38:45 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (_materia[i])
            delete _materia[i];
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    *this = src;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
            _materia[i] = rhs._materia[i];
    }
    return *this;
}

void    MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
        if (_materia[i] == NULL)
        {
            _materia[i] = m;
            return;
        }
}

AMateria*   MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < 4; i++)
        if (_materia[i] && _materia[i]->getType() == type)
            return _materia[i]->clone();
    return 0;
}
