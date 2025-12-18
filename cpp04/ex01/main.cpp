/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:58:29 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/18 16:48:30 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
std::cout << "\n========== SUBJECT TESTS ==========" << std::endl;
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;

std::cout << "\n========== ARRAY TESTS ==========" << std::endl;
std::cout << "\n--- Creating Dogs ---" << std::endl;
Animal* animals[10];

for (int k = 0; k < 5; k++)
	animals[k] = new Dog();

std::cout << "\n--- Creating Cats ---" << std::endl;
for (int k = 5; k < 10; k++)
	animals[k] = new Cat();

std::cout << "\n--- Deleting Animals ---" << std::endl;
for (int k = 0; k < 10; k++)
	delete animals[k];

std::cout << "\n========== DEEP COPY TESTS (DOG) ==========" << std::endl;
std::cout << "--- Creating dog1 and adding ideas ---" << std::endl;
Dog dog1;
dog1.addIdea("I want a bone.");
dog1.addIdea("I love my owner.");
dog1.addIdea("Squirrel!!!");

std::cout << "\n--- Testing copy constructor (dog2 = copy of dog1) ---" << std::endl;
Dog dog2(dog1);
std::cout << "dog1 idea[0]: " << dog1.getIdea(0) << std::endl;
std::cout << "dog1 idea[1]: " << dog1.getIdea(1) << std::endl;
std::cout << "dog1 idea[2]: " << dog1.getIdea(2) << std::endl;
std::cout << "dog2 idea[0]: " << dog2.getIdea(0) << std::endl;

std::cout << "\n--- Modifying dog2's ideas to prove deep copy ---" << std::endl;
dog2.setIdea(2, "I am dog2 and I don't like bones.");
std::cout << "dog1 idea[2]: " << dog1.getIdea(2) << std::endl;
std::cout << "dog2 idea[2]: " << dog2.getIdea(2) << std::endl;

std::cout << "\n--- Testing assignment operator (dog3 = dog1) ---" << std::endl;
Dog dog3;
dog3 = dog1;
std::cout << "dog1 idea[1]: " << dog1.getIdea(1) << std::endl;
std::cout << "dog3 idea[1]: " << dog3.getIdea(1) << std::endl;

std::cout << "\n--- Modifying dog3's ideas to prove deep copy ---" << std::endl;
dog3.addIdea("I am dog3 and I want a treat!");
std::cout << "dog1 idea[3]: " << dog1.getIdea(3) << std::endl;
std::cout << "dog3 idea[3]: " << dog3.getIdea(3) << std::endl;

std::cout << "\n========== DEEP COPY TESTS (CAT) ==========" << std::endl;
std::cout << "--- Creating cat1 and adding ideas ---" << std::endl;
Cat cat1;
cat1.addIdea("I want fish!");
cat1.addIdea("I need a nap.");
cat1.addIdea("I own this human. I'm its owner.");

std::cout << "\n--- Testing copy constructor (cat2 = copy of cat1) ---" << std::endl;
Cat cat2(cat1);
std::cout << "cat1 idea[0]: " << cat1.getIdea(0) << std::endl;
std::cout << "cat2 idea[0]: " << cat2.getIdea(0) << std::endl;

std::cout << "\n--- Modifying cat2's ideas to prove deep copy ---" << std::endl;
cat2.setIdea(2, "I am cat2 and my second name is Independence.");
std::cout << "cat1 idea[2]: " << cat1.getIdea(2) << std::endl;
std::cout << "cat2 idea[2]: " << cat2.getIdea(2) << std::endl;

std::cout << "\n--- Testing assignment operator (cat3 = cat1) ---" << std::endl;
Cat cat3;
cat3 = cat1;
std::cout << "cat1 idea[1]: " << cat1.getIdea(1) << std::endl;
std::cout << "cat3 idea[1]: " << cat3.getIdea(1) << std::endl;

std::cout << "\n--- Modifying cat3's ideas to prove deep copy ---" << std::endl;
cat3.setIdea(1, "I am cat3 and this keyboard is MINE.");
std::cout << "cat1 idea[1]: " << cat1.getIdea(1) << std::endl;
std::cout << "cat3 idea[1]: " << cat3.getIdea(1) << std::endl;

std::cout << "\n========== POLYMORPHIC SOUND TESTS ==========" << std::endl;
Animal* a = new Dog();
Animal* b = new Cat();
a->makeSound();
b->makeSound();
delete a;
delete b;
std::cout << "\n========== END OF PROGRAMME ==========" << std::endl;
return (0);
}