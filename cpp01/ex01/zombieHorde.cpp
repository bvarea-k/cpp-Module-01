/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:35:33 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/21 12:18:59 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {
	int		created = 0;
	Zombie	*horde;

	if (N <= 0)
		return (NULL);
	horde = new Zombie[N];

	while (created < N) {
		horde[created].setName(name);
		created++;
	}
	return (horde);
}