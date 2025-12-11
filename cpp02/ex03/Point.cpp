/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:52:54 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/10 10:57:41 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	std::cout << "Constructor called" << std::endl;
}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {
	std::cout << "Copy constructor called" << std::endl;
}

Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }
