/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:03:29 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/11 09:42:47 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	std::cout << "\n--- Creating DiamondTrap A ---" << std::endl;
	DiamondTrap a("Alpha");
	a.whoAmI();
	a.attack("Patatation");
	a.beRepaired(10);
	a.takeDamage(20);

	std::cout << "\n--- Creating DiamondTrap B (default) ---" << std::endl;
	DiamondTrap b;
	b.whoAmI();

	std::cout << "\n--- Copy Constructing C from A ---" << std::endl;
	DiamondTrap c(a);
	c.whoAmI();

	std::cout << "\n--- Assigning B = A ---" << std::endl;
	b = a;
	b.whoAmI();

	std::cout << "\n---Testing attacks and energy points ---" << std::endl;
	for (int i = 0; i < 3; i++) {
		a.attack("Dr. Evil");
	}

	std::cout << "\n--- End of main, destructors should trigger ---" << std::endl;	
	return (0);
}
