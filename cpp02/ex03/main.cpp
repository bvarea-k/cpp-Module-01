/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:37:51 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/02 16:52:30 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	Point p1(5, 5);
	Point p2(5, 0);
	Point p3(-1, 5);
	Point p4(5, 10);
	Point p5(3, 7);

	std::cout << "Is p1 inside? " << bsp(a, b, c, p1) << std::endl;
	std::cout << "Is p2 inside? " << bsp(a, b, c, p2) << std::endl;
	std::cout << "Is p3 inside? " << bsp(a, b, c, p3) << std::endl;
	std::cout << "Is p4 inside? " << bsp(a, b, c, p4) << std::endl;
	std::cout << "Is p5 inside? " << bsp(a, b, c, p5) << std::endl;

	return (0);
}
