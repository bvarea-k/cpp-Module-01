/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:23:27 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/18 14:15:45 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;						//frees current brain
		_brain = new Brain(*other._brain);	//deep copy
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}
		
void Cat::makeSound() const {
	std::cout << "Meow, meow!" <<std::endl;
}

bool Cat::addIdea(std::string idea) {
	return _brain->addIdea(idea);
}

std::string Cat::getIdea(int index) const {
	return _brain->getIdea(index);
}