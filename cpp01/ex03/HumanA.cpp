/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:49:55 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/03 09:11:25 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) {
	_name = name;
	_weapon = &weapon;
	std::cout << "HumanA " << _name << " created." << std::endl;
}

HumanA::~HumanA() {
	std::cout << "HumanA " << _name << " destroyed." << std::endl;
}

void	HumanA::attack() const {
	std::cout << _name << " attacks with their "
		<< _weapon->getType() << std::endl;
}