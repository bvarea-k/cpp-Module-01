/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:49:38 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/19 15:54:50 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria("cure"){
	std::cout << "Cure copy constructor called" << std::endl;
	(void)other; // Type should not be copied
}

Cure & Cure::operator=(Cure const &other) {
	std::cout << "Cure copy assignment operator called" << std::endl;
	(void)other; // Type should not be copied
	return (*this);
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}