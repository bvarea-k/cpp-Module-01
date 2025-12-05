/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:12:39 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/05 17:04:31 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), _name("Default") {
	_hitPoints    = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap: Default constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {

	_hitPoints    = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << "DiamondTrap: Constructor called for " << _name << std::endl;
}

/*TO DO: why is this wrong????*/

DiamondTrap::DiamondTrap(const DiamondTrap &other)
: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
	std::cout << "DiamondTrap: Copy constructor called for " << other._name << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
	

	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "DiamondTrap: Copy assignment operator called for " << _name
				<< " = " << other._name << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap: Destructor called for " << _name << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "My shinny name: " << _name
			<< " | ClapTrap name: " << ClapTrap::_name << std::endl;
}



