/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:47:32 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/11 16:47:33 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout <<  "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "AAnimal constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
	std::cout << "AAnimal copy constructor called." << std::endl;
	_type = other._type;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	std::cout << "AAnimal copy assignment operator called." << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called." << std::endl;
}

std::string AAnimal::getType() const {
	return _type;
}