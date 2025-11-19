/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:01:52 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/19 12:02:59 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0), count(0) {};

int isAscii(char c)
{
	return (c >= 32 && c <= 126);
}

int isAsciiString(const std::string &s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!isAscii(s[i]))
 			return (0);
	}
	return (1);
}


int isDigitString(const std::string &s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]))
 			return (0);
	}
	return (1);
}


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

/*Va sacando prompts en los que pide info y se guarda la info en input*/
void	PhoneBook::addContact()
{
	std::string	input;					//Declaro la variable input
	Contact	&c = contacts[nextIndex];	//Declaro la variable c y la igualo a contacts[nextIndex]. c es tipo Contact y va referenciada.

	std::cout << "Enter First Name: ";
	while (true)
	{
		std::getline(std::cin, input);
		if (!isAsciiString(input)){
			std::cout << "Error: only ASCII characters are allowed.";
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
		std::getline(std::cin, input);
		if (!isAsciiString(input)){
			std::cout << "Error: only ASCII characters are allowed.";
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
		std::getline(std::cin, input);
		if (!isAsciiString(input)){
			std::cout << "Error: only ASCII characters are allowed.";
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
		std::getline(std::cin, input);
		if (!isDigitString(input)){
			std::cout << "Error: only numbers are allowed.";
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
		std::getline(std::cin, input);
		if (!isAsciiString(input)){
			std::cout << "Error: only ASCII characters are allowed.";
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
}

void PhoneBook::searchContacts()
{
	if (count == 0) {
		std::cout << "PhoneBook is empty.\n";
		return;
	}

	std::cout << std::setw(10) << "Index" << "|"		//Creo una tabla preciosa
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname";
			std::cout << std::endl;
			
	for (int i = 0; i < count; i++) {
		std::cout << std::setw(10) << i << "|";			//Reservame 10 espacios y escribe i(el número)

		std::string fn = contacts[i].getFirstName();	//declaro variables y consigo la info con getters
		std::string ln = contacts[i].getLastName();
		std::string nn = contacts[i].getNickName();

		if (fn.size() > 10)							//Si fn mide más de 10
			fn = fn.substr(0, 9) + ".";					//crea una copia de 9 caracteres de fn y añade un punto
		if (ln.size() > 10)
			ln = ln.substr(0, 9) + ".";
		if (nn.size() > 10)
			nn = nn.substr(0, 9) + ".";

		std::cout << std::setw(10) << fn << "|"
					<< std::setw(10) << ln << "|"
					<< std::setw(10) << nn;
		std::cout << std::endl;
	}

	std::string input;									//Creo la variable input
	int index = -1;										//Creo el indice que consultará el usuario
	std::cout << "Enter index of contact to display: ";
	std::getline(std::cin, input);

	std::stringstream ss(input);						//creo 1 stringstream, para tratar un string como si fuera un flujo de entrada/salida
	//permite leer de un string como si fuera str::cin, o sea puedo usar >> para sacar valores del string
	ss >> index;

	if (ss.fail()) {									//si no puedo guardar en index un número entero, fallo. Ej. me dan abc
		std::cout << "Invalid index.\n";
		return;
	}
	if (index < 0 || index >= count) {
		std::cout << "Index out of range.\n";
		return;
	}

	printContact(index);
}
