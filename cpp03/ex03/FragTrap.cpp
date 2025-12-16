/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:36:13 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/16 10:09:28 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default Frag"){
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap: Default constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap: Constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap: Copy constructor called for " << other._name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap: Copy assignment operator called for " << _name
				<< " = " << other._name << std::endl;

	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap: Destructor called for " << _name << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " says: 'Give me five, man!'" << std::endl;
}