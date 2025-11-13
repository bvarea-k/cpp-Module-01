/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:56:12 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/12 09:56:17 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
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

// static_cast<char> es más seguro que castear con char.
//Sin el casteo, debe imprimir el int porque toupper devuelve un int. Must check
