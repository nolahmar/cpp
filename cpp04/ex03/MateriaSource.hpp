/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:22:08 by nolahmar          #+#    #+#             */
/*   Updated: 2023/12/22 16:02:37 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_materia[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(MateriaSource const &);
        MateriaSource&  operator=(MateriaSource const &);
        AMateria*       createMateria(std::string const & type);
        void            learnMateria(AMateria*);
};

#endif 


