/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:01:52 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/27 11:40:33 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0), count(0) {};

static int isAscii(char c) {
	return (c >= 32 && c <= 126);
}

static int isAsciiString(const std::string &s) {
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!isAscii(s[i]))
 			return (0);
	}
	return (1);
}

static int isDigitString(const std::string &s) {
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]))
 			return (0);
	}
	return (1);
}

void PhoneBook::printContact(int index) const {
	if (index < 0 || index >= count)
		return ;

	const Contact &c = contacts[index];
	std::cout << "First Name: " << c.getFirstName() << std::endl;
	std::cout << "Last Name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickName() << std::endl;
	std::cout << "Phone Number: " << c.getPhoneNum() << std::endl;
	std::cout << "Darkest Secret: " << c.getSecret() << std::endl;
}

/*It shows prompts that request info and saves it in input*/

bool PhoneBook::addContact() {
	std::string	input;
	Contact	&c = contacts[nextIndex];

	std::cout << "Enter First Name: ";
	while (true)
	{
		if (!std::getline(std::cin, input))
		{
			return false;
		}
		if (input.empty()) {
			std::cerr << "Error: fields cannot be empty.";
			std::cout << std::endl;
			std::cout << "Enter First Name: ";
			continue ;
		}
		if (!isAsciiString(input)){
			std::cerr << "Error: only ASCII characters are allowed.";
			std::cout << std::endl;
			std::cout << "Enter First Name: ";
			continue ;
		}
		break ;
	}
	c.setFirstName(input);

	std::cout << "Enter Last Name: ";
	while (true)
	{
		if (!std::getline(std::cin, input))
		{
			return (false);
		}
		if (input.empty()) {
			std::cerr << "Error: fields cannot be empty.";
			std::cout << std::endl;
			std::cout << "Enter Last Name: ";
			continue ;
		}
		if (!isAsciiString(input)){
			std::cerr << "Error: only ASCII characters are allowed.";
			std::cout << std::endl;
			std::cout << "Enter Last Name: ";
			continue ;
		}
		break ;
	}
	c.setLastName(input);

	std::cout << "Enter Nickname: ";
	while (true)
	{
		if (!std::getline(std::cin, input))
		{
			return false;
		}
		if (input.empty()) {
			std::cerr << "Error: fields cannot be empty.";
			std::cout << std::endl;
			std::cout << "Enter Nickname: ";
			continue ;
		}
		if (!isAsciiString(input)){
			std::cerr << "Error: only ASCII characters are allowed.";
			std::cout << std::endl;
			std::cout << "Enter Nickname: ";
			continue ;
		}
		break ;
	}
	c.setNickName(input);

	std::cout << "Enter Phone Number: ";
	while (true)
	{
		if (!std::getline(std::cin, input))
		{
			return false;
		}
		if (input.empty()) {
			std::cerr << "Error: fields cannot be empty.";
			std::cout << std::endl;
			std::cout << "Enter Phone Number: ";
			continue ;
		}
		if (!isDigitString(input)){
			std::cerr << "Error: only numbers are allowed.";
			std::cout << std::endl;
			std::cout << "Enter Phone Number: ";
			continue ;
		}
		break ;
	}
	c.setPhoneNum(input);

	std::cout << "Enter Darkest Secret: ";
	while (true)
	{
		if (!std::getline(std::cin, input))
		{
			return false;
		}
		if (input.empty()) {
			std::cerr << "Error: fields cannot be empty.";
			std::cout << std::endl;
			std::cout << "Enter Darkest Secret: ";
			continue ;
		}
		if (!isAsciiString(input)){
			std::cerr << "Error: only ASCII characters are allowed.";
			std::cout << std::endl;
			std::cout << "Enter Darkest Secret: ";
		continue ;
		}
		break ;
	}
	c.setSecret(input);

	nextIndex = (nextIndex + 1) % 8;
	if (count < 8)
		count++;

	std::cout << "Contact added successfully!";
	std::cout << std::endl;
	return true;
}

bool PhoneBook::searchContacts()
{
	if (count == 0) {
		std::cout << "PhoneBook is empty." << std::endl;
		return true;
	}

	std::cout << std::setw(10) << "Index" << "|"		//To create the table
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname";
			std::cout << std::endl;
			
	for (int i = 0; i < count; i++) {
		std::cout << std::setw(10) << i << "|";

		std::string fn = contacts[i].getFirstName();	//I declare variables and get the info with getters
		std::string ln = contacts[i].getLastName();
		std::string nn = contacts[i].getNickName();

		if (fn.size() > 10)
			fn = fn.substr(0, 9) + ".";					//creates a 9 char copy and adds full stop
		if (ln.size() > 10)
			ln = ln.substr(0, 9) + ".";
		if (nn.size() > 10)
			nn = nn.substr(0, 9) + ".";

		std::cout << std::setw(10) << fn << "|"
					<< std::setw(10) << ln << "|"
					<< std::setw(10) << nn;
		std::cout << std::endl;
	}

	std::string input;
	int index = -1;										//Index that the user will check
	std::cout << "Enter index of contact to display: ";
	if (!std::getline(std::cin, input))
		return false;

	std::stringstream ss(input);						//stringstream allows to read a string as if it was str::cin
	ss >> index;

	if (ss.fail()) {
		std::cout << "Invalid index." << std::endl;
		return true;
	}
	if (index < 0 || index >= count) {
		std::cout << "Index out of range." << std::endl;
		return true;
	}

	printContact(index);
	return true;
}
