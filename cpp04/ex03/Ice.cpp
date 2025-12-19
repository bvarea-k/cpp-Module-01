/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:09:21 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/19 15:48:54 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria("ice") {
	std::cout << "Ice copy constructor called" << std::endl;
	(void)other; // Type should not be copied
}

Ice &Ice::operator=(Ice const &other) {
	std::cout << "Ice copy assignment operator called" << std::endl;
	(void)other; // Type should not be copied
	return (*this);
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}