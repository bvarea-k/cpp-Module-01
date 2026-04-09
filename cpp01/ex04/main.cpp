/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:28:19 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/03 09:53:26 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

/*npos is a constant of std::string that means "not found"*/

std::string	myReplace(const std::string &line,
						const std::string &s1, const std::string &s2) {
	std::string	result;
	size_t		pos = 0;
	size_t		found = line.find(s1, pos);

	while (found != std::string::npos) {
		result.append(line, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
		found = line.find(s1, pos);
	}
	result.append(line, pos, std::string::npos);
	return (result);
}

int	main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "Error. Enter: ./Sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return (1);
	}

	std::ifstream in(filename.c_str());			/*Constructors in c++98 don't accept std::string, only const char**/
	if (!in.is_open()) {
		std::cerr << "Error: could not open input file." << std::endl;
		return (1);
	}

	std::ofstream out((filename + ".replace").c_str());
	if (!out.is_open()) {
		std::cerr << "Error: could not open output file." << std::endl;
		return (1);
	}

	std::string line;
	while (std::getline(in, line)) {
		out << myReplace(line, s1, s2);
		if (!in.eof())
			out << std::endl;
	}

	return (0);
}


