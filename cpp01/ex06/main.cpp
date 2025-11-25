/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:16:51 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/25 12:12:52 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harlFilter.hpp"

int	main(int ac, char **av) {
	Harl harl;
	
	if (ac == 2)
		harl.complainFilter(av[1]);
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return (0);
}

