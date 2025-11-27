/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:17:56 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/27 13:27:16 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/*using std::cout;
using std::endl;*/

class Fixed {
	private:
		int					_numberValue;
		static const int	fractionalBits = 8;

	public:
		Fixed();									//Default constructor
		Fixed(const Fixed &other);					//Copy constructor
		Fixed(const int value);						//Int constructor
		Fixed(const float value);					//Float constructor
		Fixed &operator=(const Fixed &other);	//Overload of = operator
		~Fixed();									//Destructor

		int		getRawBits( void ) const;
		void	setRawBits ( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif