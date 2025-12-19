/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:47:11 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/19 13:10:53 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
	{
	std::cout << "=== Testing Animal, Dog, Cat ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	std::cout << "\n=== Deleting (testing virtual destructors) ===" << std::endl;
	delete meta;
	delete j;
	delete i;
	
	std::cout << "\n=== Testing WrongAnimal, WrongCat ===" << std::endl;
	const WrongAnimal* unicorn = new WrongAnimal();
	const WrongAnimal* c = new WrongCat();
	std::cout << c->getType() << " " << std::endl;
	c->makeSound();
	unicorn->makeSound();
	
	std::cout << "\n=== Deleting Wrong classes ===" << std::endl;
	delete unicorn;
	delete c;
	
	std::cout << "\n=== Testing copy constructor ===" << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	dog2.makeSound();
	
	std::cout << "\n=== Testing assignment operator ===" << std::endl;
	Cat cat1;
	Cat cat2;
	cat2 = cat1;
	cat2.makeSound();
	
	return 0;
}