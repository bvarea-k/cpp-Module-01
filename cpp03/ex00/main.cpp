/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:03:29 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/04 17:04:42 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main(void)
{
	// --- Constructor with parametters ---
	ClapTrap clap1("Astrocat");
	std::cout << "\n--- Attack, damage and heal tests---\n";
	clap1.attack("super evil enemy");
	clap1.takeDamage(5);
	clap1.beRepaired(3);
	clap1.takeDamage(10);
	clap1.attack("super evil enemy");
	clap1.beRepaired(3);
	
	// --- Default constructor ---
	std::cout << "\n--- Default constructor test ---\n";
	ClapTrap clap2;
	clap2.attack("the air");
	
	// --- Copy constructor ---
	std::cout << "\n--- Copy constructor test ---\n";
	ClapTrap clap3(clap1); 
	clap3.attack("copy enemy");	

	// --- Copy assignment operator ---
	std::cout << "\n--- Copy assignment operator test ---\n";
	ClapTrap clap4;
	clap4 = clap1;
	clap4.beRepaired(5);

	// --- Can it do anything if it's dead? ---
	std::cout << "\n--- Can it do anything if it's dead? ---\n";
	for (int i = 0; i < 12; i++)
		clap4.attack("exhausted enemy");

	std::cout << "\n--- Probando HP = 0 ---\n";
	clap4.takeDamage(50);
	clap4.beRepaired(10);	
	return (0);
}

