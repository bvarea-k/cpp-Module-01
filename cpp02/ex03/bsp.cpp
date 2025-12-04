/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:59:57 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/03 16:13:19 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float cross(Point const p1, Point const p2, Point const p3) {
    // (p2 - p1) × (p3 - p1)
    return (p2.getX().toFloat() - p1.getX().toFloat()) *
           (p3.getY().toFloat() - p1.getY().toFloat()) -
           (p2.getY().toFloat() - p1.getY().toFloat()) *
           (p3.getX().toFloat() - p1.getX().toFloat());
}


bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d1 = cross(a, b, point);
	float d2 = cross(b, c, point);
	float d3 = cross(c, a, point);

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	if (has_neg && has_pos)
		return false;

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;

	return true;
}



/*float cross(Point const p1, Point const p2, Point const p3)
{
    float x1 = p2.getX().toFloat() - p1.getX().toFloat();
    float y1 = p2.getY().toFloat() - p1.getY().toFloat();
    float x2 = p3.getX().toFloat() - p1.getX().toFloat();
    float y2 = p3.getY().toFloat() - p1.getY().toFloat();

    return x1 * y2 - y1 * x2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float d1 = cross(a, b, point);
    float d2 = cross(b, c, point);
    float d3 = cross(c, a, point);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    // Si hay mezcla de signos => fuera
    if (has_neg && has_pos)
        return false;

    // Si está demasiado cerca de un borde => fuera (excluye bordes)
    if (fabs(d1) < 0.0001f || fabs(d2) < 0.0001f || fabs(d3) < 0.0001f)
        return false;

    return true;
}*/


