/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:37:44 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/03 09:01:32 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
/*#include <cstdlib>

int	main(int ac, char **av) {
	if (ac != 3) {
		std::cout << "Enter ./a.out, a number and a name" << std::endl;
		return (1);
	}
	int	N = atoi(av[1]);
	std::string name =av[2];
	Zombie *horde = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}*/

int	main() {
	Zombie *horde = zombieHorde(4, "Paquete");
	for (int i = 0; i < 4; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}


