/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:43:14 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/17 12:23:00 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout <<  "Wrong Animal default constructor called.." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "Wrong animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "Wrong animal copy constructor called" << std::endl;
	_type = other._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "Wrong animal copy assignment operator called." << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong animal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << _type << "Makes a generic sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}