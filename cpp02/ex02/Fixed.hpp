/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:17:56 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/28 17:01:28 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

/*using std::cout;
using std::endl;*/

class Fixed {
	private:
		int					_numberValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed();									//Default constructor
		Fixed(const Fixed &other);					//Copy constructor
		Fixed(const int value);						//Int constructor
		Fixed(const float value);					//Float constructor
		Fixed &operator=(const Fixed &other);		//Overload of = operator
		Fixed operator+(const Fixed &other) const; //no need of & cause they don't modify a value, but create a new value
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		
		bool operator>(const Fixed &other) const;	//Must be bool because it's a true false comparison
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed &operator++(void);					// Pre-increment
		Fixed operator++(int);						// Post-increment
		Fixed &operator--(void);					// Pre-decrement
		Fixed operator--(int);						// Post-decrement


		~Fixed();									//Destructor

		int			getRawBits( void ) const;
		void		setRawBits ( int const raw );
		float		toFloat( void ) const;
		int			toInt( void ) const;
	
		static Fixed	&min(Fixed &f1, Fixed &f2);
		static Fixed	&max(Fixed &f1, Fixed &f2);
		static const	Fixed &min(const Fixed &f1, const Fixed &f2);
		static const	Fixed &max(const Fixed &f1, const Fixed &f2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

/*My class doesnt save afixed-point, but an int (_numberValue)
that represents a number with 8 bits after the point.
if _numberValue = 256, 1.0
if _numberValue = 512, 2.0
real number = _numberValue/256 
This and this are the same: value << 8 = value * 256 */