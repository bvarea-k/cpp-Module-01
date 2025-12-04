/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:02:07 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/04 13:30:24 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	:	_name (other._name),
		_hitPoints (other._hitPoints),
		_energyPoints (other._energyPoints),
		_attackDamage (other._attackDamage) {
			std::cout << "Copy constructor called." << std::endl;
}

/*ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap copy constructor called." << std::endl;
	*this = other;
}
*/

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called." << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (_hitPoints < 1) {
		std::cout << "ClapTrap " << _name << " is dead." << std::endl;
		return ;
	}
	if (_energyPoints < 1) {
		std::cout << "ClapTrap " << _name << " has no energy points left to attack" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "<< _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints < 1) {
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints = _hitPoints - amount;
	std::cout << "ClapTrap " << _name << " has received " << amount << " points of damage!" << std::endl;
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead. RIP." << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " has " << _hitPoints << " left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints < 1) {
		std::cout <<"ClapTrap " << _name << " is already dead and cannot be healed." << std::endl;
		return ;
	}
	if (_energyPoints < 1) {
		std::cout << "ClapTrap " << _name << " has no energy points left to heal." << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints = _hitPoints + amount;
	std::cout << "ClapTrap " << _name << " has recovered " << amount << " hit points." << std::endl;
}
