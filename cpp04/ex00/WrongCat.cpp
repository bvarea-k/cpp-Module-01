/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:45:03 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/17 11:47:56 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	_type = "Wrong cat";
	std::cout << "Wrong cat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "Wrong cat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "Wrong cat copy assignment operator called." << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "Wrong cat destructor called" << std::endl;
}
		
void WrongCat::makeSound() const {
	std::cout << "Meow, meow!" <<std::endl;
}