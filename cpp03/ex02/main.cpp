/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:03:29 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/05 14:10:32 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
FragTrap (derived)
├── ClapTrap (base)
│   ├── _name
│   ├── _hitPoints
│   ├── _energyPoints
│   └── _attackDamage
├── FragTrap-specific methods
│   └── highFivesGuys()
└── Constructors / destructors / operators
*/

int main(void)
{
	std::cout << "--- Creating FragTraps ---" << std::endl;
	FragTrap frag1("Fraguncio");
	FragTrap frag2;

	std::cout << "\n--- FragTrap actions ---" << std::endl;

	frag1.attack("target1");
	frag1.takeDamage(20);
	frag1.beRepaired(10);
	frag1.highFivesGuys();

	std::cout << std::endl;

	frag2.attack("target2");
	frag2.takeDamage(5);
	frag2.beRepaired(3);
	frag2.highFivesGuys();	
	std::cout << "\n--- Testing Canonical Form ---" << std::endl;	

	FragTrap copyFrag(frag1);       // copy constructor
	FragTrap assignedFrag;
	assignedFrag = frag2;            // copy assignment operator	

	std::cout << "\n--- End of tests ---" << std::endl;
	return (0);
}

