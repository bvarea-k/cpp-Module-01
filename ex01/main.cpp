/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:42:13 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/17 16:07:17 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void){
	PhoneBook	phonebook;										//llamo al constructor PhoneBook::PhoneBook() : nextIndex(0), count(0) {}
	std::string	command;										//creo una variable para guardar mis comandos

	while (1){
		std::cout << "Enter command ADD, SEARCH or EXIT: ";
		std::getline(std::cin, command);						//Lee y todo lo que se escriba va a command
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command.\n";
	}
	return (0);
}
