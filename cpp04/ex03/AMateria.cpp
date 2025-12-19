/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:00:15 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/19 14:08:49 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
	this->_type = "defaultMateria";
}

AMateria::AMateria(std::string const & type) {
	std::cout << "AMateria constructor called" << std::endl;
	this->_type = type;
}

AMateria::AMateria(AMateria const &other) {
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(AMateria const &other) {
	std::cout << "AMateria assignment operator called" << std::endl;
	(void)other; // Type should not be copied
	return (*this);
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
}