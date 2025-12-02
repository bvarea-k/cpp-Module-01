/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:40:56 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/02 16:22:53 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
	Fixed const	_x;
	Fixed const _y;
	Point &operator=(const Point &other);
	
	public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};

#endif
