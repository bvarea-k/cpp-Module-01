/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:42:13 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/26 09:56:22 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void){
	PhoneBook	phonebook;
	std::string	command;

	while (1){
		std::cout << "Enter command ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, command)){
			std::cerr << "\nEOF detected. Exiting." << std::endl;
			return (0);
		}
		if (command == "ADD")  {
			if (!phonebook.addContact()) {
				std::cerr << "\nEOF detected. Exiting." << std::endl;
				return (0);
			}
		}
		else if (command == "SEARCH") {
			if (!phonebook.searchContacts()) {
				std::cerr << "\nEOF detected. Exiting." << std::endl;
				return (0);
			}
		}
		else if (command == "EXIT") {
			break;
		}
		else
			std::cerr << "Invalid command." << std::endl;
	}
	return (0);
}
