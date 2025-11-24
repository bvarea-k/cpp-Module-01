/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:16:51 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/24 17:08:48 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av) {
	Harl harl;
	
	if (ac == 2)
		harl.complain(av[1]);
	else
		std::cerr << "Error. Enter ./harlFilter <instruction" << std::endl;
	return (0);
}
