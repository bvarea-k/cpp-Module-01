/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:03:29 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/01 16:11:59 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main (void) {
	ClapTrap ClapTrap("Astrocat");
	
	ClapTrap.attack("super evil enemy");
	ClapTrap.takeDamage(5);
	ClapTrap.beRepaired(3);
	ClapTrap.takeDamage(10);
	ClapTrap.attack("super evil enemy");
	ClapTrap.beRepaired(3);
	return (0);
}
