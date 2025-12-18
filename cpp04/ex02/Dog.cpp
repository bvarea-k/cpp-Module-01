/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:29:09 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/18 17:02:33 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete _brain;						//frees current brain
		_brain = new Brain(*other._brain);	//deep copy
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}
		
void Dog::makeSound() const {
	std::cout << "Woof, woof!" <<std::endl;
}

bool Dog::addIdea(std::string idea) {
	return _brain->addIdea(idea);
}

std::string Dog::getIdea(int index) const {
	return _brain->getIdea(index);
}

void Dog::setIdea(int index, std::string idea) {
	_brain->setIdea(index, idea);
}