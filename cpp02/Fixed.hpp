/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:17:56 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/25 16:36:54 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int	_numberValue;
		static const int	fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed & operator = (const Fixed &other);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits ( int const raw );
};

#endif