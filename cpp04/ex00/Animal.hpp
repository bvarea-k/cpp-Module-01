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
		Animal();								//Default constructor
		Animal(std::string type);				//Parameterized constructor
		Animal(const Animal &other);			//Copy constructor
		Animal &operator=(const Animal &other);	//Copy assignment operator
		virtual ~Animal();						//Destructor

		virtual void makeSound() const;
		std::string getType() const;
};

#endif