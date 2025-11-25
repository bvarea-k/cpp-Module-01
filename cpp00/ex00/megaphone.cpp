/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:56:12 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/25 09:40:28 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

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

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	if (!isAsciiString(argv[1])){
			std::cerr << "Error: only ASCII characters are allowed.";
			std::cout << std::endl;
		return (0);
		}
	for (int i = 1; i < argc; ++i)
	{
		for (int j = 0; argv[i][j]; ++j)
		{
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
		}
	}
	std::cout << std::endl;
	return (0);
}

// static_cast<char> safer than simply casting.
//Must cast to char cause toupper returns an int.
