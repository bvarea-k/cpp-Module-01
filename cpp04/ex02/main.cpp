/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:58:29 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/18 17:06:06 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "========== TEST: AAnimal is abstract ==========" << std::endl;	
	std::cout << "Creating Dog and Cat (derived from AAnimal):" << std::endl;
	AAnimal* dog = new Dog();
	AAnimal* cat = new Cat();	
	dog->makeSound(); // Woof, woof!
	cat->makeSound(); // Meow, meow!	
	delete dog;
	delete cat;	
	
	std::cout << "========== END OF TEST ==========" << std::endl;
	return (0);
}
