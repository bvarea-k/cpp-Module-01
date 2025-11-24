/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:28:19 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/24 13:13:03 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void	myReplace() {
	std::ifstream in(filename);
	std::string outFilename =filename + ".replace";
	std::ofstream(filename.replace);

    if (!in.is_open()) {
        std::cerr << "Couldn't open file." << std::endl;
        return ;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::cout << line << std::endl;
    }
}

int	main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "You must enter 4 parameters." << std::endl;
		return (1);
	}
    
}

