/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:03:29 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/16 09:17:08 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	// --- Constructor with parametters ---
	ClapTrap clap1("Astrocat");
	std::cout << "\n--- Attack, damage and heal tests---" << std::endl;
	clap1.attack("super evil enemy");
	clap1.takeDamage(5);
	clap1.beRepaired(3);
	clap1.takeDamage(6);
	clap1.attack("super evil enemy");
	clap1.beRepaired(3);
	
	// --- Default constructor ---
	std::cout << "\n--- Default constructor test" << std::endl;
	ClapTrap clap2;
	clap2.attack("the air");
	
	// --- Copy constructor ---
	std::cout << "\n--- Copy constructor test" << std::endl;
	ClapTrap clap3(clap1); 
	clap3.attack("copy enemy");

	// --- Copy assignment operator ---
	std::cout << "\n--- Copy assignment operator test ---" << std::endl;
	ClapTrap clap4;
	clap4 = clap1;
	clap4.takeDamage(5);

	// --- No energy points left ---
	std::cout << "\n--- Running out of energy points ---" << std::endl;
	for (int i = 0; i < 12; i++)
		clap2.attack("exhausted enemy");

	// --- What happens if dead? ---
	std::cout << "\n--- What happens if dead? ---" << std::endl;
	clap2.takeDamage(50);
	clap2.beRepaired(10);
	clap2.attack("evil enemy");
	clap2.takeDamage(1);
	
	std::cout << "\n--- End of tests ---" << std::endl;
	return (0);
}

