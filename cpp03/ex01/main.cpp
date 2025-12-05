/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:03:29 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/05 12:14:13 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {

	ClapTrap Clap("Astrocat");
	ScavTrap Scav("Superdog");

	std::cout << "\n--- Testing ClapTrap ---" << std::endl;
	Clap.attack("target");
	Clap.takeDamage(5);
	Clap.beRepaired(3);
	Clap.attack("target");
	Clap.takeDamage(10);
	Clap.beRepaired(5);
	Clap.attack("target");
	Clap.takeDamage(10);
	Clap.beRepaired(5);	

	std::cout << "\n--- Testing ScavTrap ---" << std::endl;
	Scav.attack("target");
	Scav.takeDamage(5);
	Scav.beRepaired(3);
	Scav.guardGate();
	Scav.attack("target");
	Scav.takeDamage(10);
	Scav.beRepaired(5);	

	std::cout << "\n--- Testing Canonical Form ---" << std::endl;
	ScavTrap copyScav(Scav);
	ScavTrap assigned;
	assigned = Scav;

	std::cout << "\n--- End of tests ---" << std::endl;
	return (0);
}

