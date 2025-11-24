/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:17:13 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/24 16:43:12 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//Do I need constructor and destructor?

Harl::Harl(){
	std::cout << "Harl has arrived." << std::endl;
}

Harl::~Harl() {
	std::cout << "Harl is gone." << std::endl;
}


// REVISE
void Harl::complain(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*functions[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

    // Buscar el nivel y llamar a la función correspondiente
    for (int i = 0; i < 4; ++i) {
        if (level == levels[i]) {
            (this->*functions[i])();
            return;
        }
    }
}

void	Harl::debug( void ) {
	std::cout << "I love having extra bacon..." << std::endl;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}