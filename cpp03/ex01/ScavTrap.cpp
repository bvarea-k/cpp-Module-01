/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:02:14 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/01 17:55:30 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//It calls the default constructor of ClapTrap and we can change the values

ScavTrap::ScavTrap() : ClapTrap("Default_Scav") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called." << std::endl;
}

//It calls ClapTrap copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called." << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is in guarding mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints < 1) {
		std::cout << "ScavTrap " << this->_name << " is dead." << std::endl;
		return ;
	}
	if (this->_energyPoints < 1) {
		std::cout << "ScavTrap " << this->_name << " has no energy points left to attack" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "<< _attackDamage << " points of damage!" << std::endl;
}