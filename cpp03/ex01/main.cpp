/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:03:29 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/01 18:01:18 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main (void) {
	ClapTrap ClapTrap("Astrocat");
	ScavTrap ScavTrap("Who");

	std::cout << "\n *****ClapTrap actions*****" << std::endl;
	ClapTrap.attack("target");
	ClapTrap.takeDamage(5);
	ClapTrap.beRepaired(3);
	ClapTrap.attack("target");
	ClapTrap.takeDamage(10);
	ClapTrap.beRepaired(5);
	ClapTrap.attack("target");
	ClapTrap.takeDamage(10);
	ClapTrap.beRepaired(5);

	std::cout << "\n *****ScavTrap actions*****" << std::endl;
	ScavTrap.attack("target");
	ScavTrap.takeDamage(5);
	ScavTrap.beRepaired(3);
	ScavTrap.attack("target");
	ScavTrap.takeDamage(10);
	ScavTrap.beRepaired(5);
	ScavTrap.attack("target");
	ScavTrap.takeDamage(10);
	ScavTrap.beRepaired(5);
	return (0);
}
