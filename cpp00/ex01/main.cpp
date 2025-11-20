/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:42:13 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/20 11:17:43 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void){
	PhoneBook	phonebook;										//llamo al constructor PhoneBook::PhoneBook() : nextIndex(0), count(0) {}
	std::string	command;										//creo una variable para guardar mis comandos

	while (1){
		std::cout << "Enter command ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, command)){
			std::cerr << "\nEOF detected. Exiting.\n";
			return (0);
		}						//Lee y todo lo que se escriba va a command
		if (command == "ADD")  {
			if (!phonebook.addContact()) {
				std::cerr << "\nEOF detected. Exiting.\n";
				return (0);
			}
		}
		else if (command == "SEARCH") {
			if (!phonebook.searchContacts()) {
				std::cerr << "\nEOF detected. Exiting.\n";
				return (0);
			}
		}
		else if (command == "EXIT") {
			break;
		}
		else
			std::cerr << "Invalid command.\n";
	}
	return (0);
}
