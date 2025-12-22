/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:05:48 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/22 09:24:08 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
class Cat : public Animal {
	public:
		Cat();								//Default constructor
		Cat(const Cat &other);				//Copy constructor
		Cat &operator=(const Cat &other);	//Copy assignment operator
		~Cat();								//Destructor
		
		void makeSound() const;
};

#endif