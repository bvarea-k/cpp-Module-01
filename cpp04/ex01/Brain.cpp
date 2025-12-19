/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:48:36 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/19 12:33:39 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignment operator called." << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

bool Brain::addIdea(std::string idea) {
	for (int i = 0; i < 100; i++)
	{
		if (this->_ideas[i].empty())
		{
			this->_ideas[i] = idea;
			return (true);
		}
	}
	return (false);
}

std::string Brain::getIdea(int index) {
	if (index < 0 || index >= 100)
		return ("Invalid index");
	return (this->_ideas[index]);
}

void Brain::setIdea(int index, std::string idea) {
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}