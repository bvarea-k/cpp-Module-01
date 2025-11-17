/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:01:52 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/17 11:41:55 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0), count(0) {};

void PhoneBook::printContact(int index) const {
    if (index < 0 || index >= count)
        return;

    const Contact &c = contacts[index];
    std::cout << "First Name: " << c.getFirstName() << "\n";
    std::cout << "Last Name: " << c.getLastName() << "\n";
    std::cout << "Nickname: " << c.getNickName() << "\n";
    std::cout << "Phone Number: " << c.getPhoneNum() << "\n";
    std::cout << "Darkest Secret: " << c.getSecret() << "\n";
}

void	PhoneBook::addContact(){
	std::string	input;
	Contact	&c = contacts[nextIndex];

	std::cout << "Enter First Name: ";
	std::getline(std::cin, input);
	c.setFirstName(input);

	std::cout << "Enter Last Name: ";
	std::getline(std::cin, input);
	c.setLastName(input);

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, input);
	c.setNickName(input);

	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, input);
	c.setPhoneNum(input);

	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, input);
	c.setSecret(input);

	nextIndex = (nextIndex + 1) % 8;
	if (count < 8)
		count++;

	std::cout << "Contact added successfully!\n";
}

void PhoneBook::searchContacts() {
	if (count == 0) {
		std::cout << "PhoneBook is empty.\n";
		return;
	}

	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "\n";

	for (int i = 0; i < count; i++) {
		std::cout << std::setw(10) << i << "|";

		std::string fn = contacts[i].getFirstName();
		std::string ln = contacts[i].getLastName();
		std::string nn = contacts[i].getNickName();

		if (fn.length() > 10)
			fn = fn.substr(0, 9) + ".";
		if (ln.length() > 10)
			ln = ln.substr(0, 9) + ".";
		if (nn.length() > 10)
			nn = nn.substr(0, 9) + ".";

		std::cout << std::setw(10) << fn << "|"
					<< std::setw(10) << ln << "|"
					<< std::setw(10) << nn << "\n";
	}

	// Request index
	std::string input;
	int index = -1;
	std::cout << "Enter index of contact to display: ";
	std::getline(std::cin, input);

	std::stringstream ss(input);
	ss >> index;

	if (ss.fail()) {
		std::cout << "Invalid index.\n";
		return;
	}
	if (index < 0 || index >= count) {
		std::cout << "Index out of range.\n";
		return;
	}

	printContact(index);
}
