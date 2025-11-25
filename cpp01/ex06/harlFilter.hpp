/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harlFilter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:17:07 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/25 12:00:28 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
	private:
			void	debug( void );
			void	info( void );
			void	warning( void );
			void	error( void );

	public:
			Harl();
			~Harl();

			void	complainFilter( std::string level );
};

#endif
