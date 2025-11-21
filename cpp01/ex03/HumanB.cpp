/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:46:43 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/21 16:56:47 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB() {
	std::cout << "HumanB " << _name << " destroyed." << std::endl;
}

void	HumanB::attack() const {
	if (_weapon != NULL)
		std::cout << _name << " attacks with their "
			<< _weapon->getType() << std::endl;
	else
	std::cout << _name << " attacks with their fists." << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}