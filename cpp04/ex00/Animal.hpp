/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:47:47 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/11 17:00:07 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
 #define ANIMAL_HPP

 # include <iostream>
 
class Animal {
	protected:
		std::string _type;
		
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		~Animal();

		virtual void makeSound() const;
		std::string getType() const;
		//void setType(std::string type);
};

#endif