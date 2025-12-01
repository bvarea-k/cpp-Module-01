/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:02:07 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/01 17:36:27 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	:	_name (other._name),
		_hitPoints (other._hitPoints),
		_energyPoints (other._energyPoints),
		_attackDamage (other._attackDamage) {
			std::cout << "Copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called." << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints < 1) {
		std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
		return ;
	}
	if (this->_energyPoints < 1) {
		std::cout << "ClapTrap " << this->_name << " has no energy points left to attack" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "<< _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints < 1) {
		std::cout << "ClapTrap " << this->_name << " is already dead." << std::endl;
		return ;
	}
	this->_hitPoints = this->_hitPoints - amount;
	std::cout << "ClapTrap " << this->_name << " has received " << amount << " points of damage!" << std::endl;
	if (this->_hitPoints < 1) {
		std::cout << "ClapTrap " << this->_name << " is dead. RIP." << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has " << this->_hitPoints << " left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints < 1) {
		std::cout <<"ClapTrap " << this->_name << " is already dead and cannot be healed." << std::endl;
		return ;
	}
	if (this->_energyPoints < 1) {
		std::cout << "ClapTrap " << this->_name << " has no energy points left to heal." << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints = this->_hitPoints + amount;
	std::cout << "ClapTrap " << this->_name << " has recovered " << amount << " hit points." << std::endl;
}
