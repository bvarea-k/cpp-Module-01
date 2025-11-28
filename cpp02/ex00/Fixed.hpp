/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:17:56 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/28 11:09:38 by bvarea-k         ###   ########.fr       */
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
		static const int	_fractionalBits = 8;

	public:
		Fixed();									//Default constructor
		Fixed(const Fixed &other);					//Copy constructor
		Fixed &operator=(const Fixed &other);	//Overload of = operator
		~Fixed();									//Destructor

		int		getRawBits( void ) const;
		void	setRawBits ( int const raw );
};

#endif