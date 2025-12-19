/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:41:16 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/19 16:54:32 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	/*std::cout << "========== SUBJECT MANDATORY TEST ==========" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());				//Intentional leaks, ice is cloned
		src->learnMateria(new Cure());				//Same, intentional leaks
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}*/

	std::cout << "\n========== TEST 1: FULL INVENTORY ==========" << std::endl;
	{
		ICharacter* hero = new Character("Hero");
		
		// Fill all 4 slots
		hero->equip(new Ice());
		hero->equip(new Cure());
		hero->equip(new Ice());
		hero->equip(new Cure());
		
		std::cout << "\nTrying to equip 5th materia (should do nothing):" << std::endl;
		AMateria* extra = new Ice();
		hero->equip(extra); // This should not equip (inventory full)
		delete extra; // Must delete since it wasn't equipped
		
		// Use all equipped materias
		ICharacter* target = new Character("Target");
		std::cout << "\nUsing all 4 equipped materias:" << std::endl;
		hero->use(0, *target);
		hero->use(1, *target);
		hero->use(2, *target);
		hero->use(3, *target);
		
		delete target;
		delete hero;
	}

	std::cout << "\n========== TEST 2: INVALID OPERATIONS ==========" << std::endl;
	{
		ICharacter* test = new Character("Test");
		test->equip(new Ice());
		test->equip(new Cure());
		
		ICharacter* dummy = new Character("Dummy");
		
		std::cout << "\nTrying invalid use() calls (should do nothing):" << std::endl;
		test->use(-1, *dummy);     // Invalid negative index
		test->use(4, *dummy);      // Invalid index >= 4
		test->use(2, *dummy);      // Empty slot
		test->use(100, *dummy);    // Way out of bounds
		
		std::cout << "\nTrying invalid unequip() calls (should do nothing):" << std::endl;
		test->unequip(-1);         // Invalid negative index
		test->unequip(10);         // Invalid index >= 4
		
		std::cout << "\nValid use after invalid operations:" << std::endl;
		test->use(0, *dummy);      // Should still work
		
		delete dummy;
		delete test;
	}

	std::cout << "\n========== TEST 3: UNEQUIP AND MEMORY MANAGEMENT ==========" << std::endl;
	{
		ICharacter* warrior = new Character("Warrior");
		ICharacter* enemy = new Character("Enemy");
		
		// Equip materias
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		warrior->equip(ice);
		warrior->equip(cure);
		
		std::cout << "\nUsing materias before unequip:" << std::endl;
		warrior->use(0, *enemy);
		warrior->use(1, *enemy);
		
		std::cout << "\nUnequipping slot 0..." << std::endl;
		// Save pointer before unequipping to avoid memory leak
		AMateria* savedMateria = ice; // We still have the pointer from line 109
		warrior->unequip(0);
		delete savedMateria; // Now properly delete the unequipped materia
		
		std::cout << "\nTrying to use unequipped slot (should do nothing):" << std::endl;
		warrior->use(0, *enemy);
		
		std::cout << "\nSlot 1 should still work:" << std::endl;
		warrior->use(1, *enemy);
		
		std::cout << "\nEquipping new materia in slot 0:" << std::endl;
		warrior->equip(new Cure());
		warrior->use(0, *enemy);
		
		delete enemy;
		delete warrior;
	}

	std::cout << "\n========== TEST 4: CHARACTER DEEP COPY ==========" << std::endl;
	{
		std::cout << "\nCreating original character with materias:" << std::endl;
		Character original("Original");
		original.equip(new Ice());
		original.equip(new Cure());
		
		std::cout << "\nCreating copy using copy constructor:" << std::endl;
		Character copy(original);
		
		std::cout << "\nUsing original's materias:" << std::endl;
		ICharacter* target1 = new Character("Target1");
		original.use(0, *target1);
		original.use(1, *target1);
		
		std::cout << "\nUsing copy's materias (should be independent):" << std::endl;
		ICharacter* target2 = new Character("Target2");
		copy.use(0, *target2);
		copy.use(1, *target2);
		
		std::cout << "\nCreating another character for assignment operator:" << std::endl;
		Character assigned("Assigned");
		assigned.equip(new Cure());
		assigned.equip(new Ice());
		
		std::cout << "\nAssigning original to assigned:" << std::endl;
		assigned = original;
		
		std::cout << "\nUsing assigned's materias:" << std::endl;
		assigned.use(0, *target2);
		assigned.use(1, *target2);
		
		delete target1;
		delete target2;
	}

	std::cout << "\n========== TEST 5: MATERIASOURCE DEEP COPY ==========" << std::endl;
	{
		std::cout << "\nCreating original MateriaSource:" << std::endl;
		MateriaSource original;
		AMateria* ice_tmp = new Ice();
		AMateria* cure_tmp = new Cure();
		original.learnMateria(ice_tmp);
		original.learnMateria(cure_tmp);
		delete ice_tmp;
		delete cure_tmp;
		
		std::cout << "\nCopying MateriaSource:" << std::endl;
		MateriaSource copy(original);
		
		std::cout << "\nCreating materias from original:" << std::endl;
		AMateria* m1 = original.createMateria("ice");
		AMateria* m2 = original.createMateria("cure");
		if (m1) std::cout << "Original created: " << m1->getType() << std::endl;
		if (m2) std::cout << "Original created: " << m2->getType() << std::endl;
		delete m1;
		delete m2;
		
		std::cout << "\nCreating materias from copy (should be independent):" << std::endl;
		AMateria* m3 = copy.createMateria("ice");
		AMateria* m4 = copy.createMateria("cure");
		if (m3) std::cout << "Copy created: " << m3->getType() << std::endl;
		if (m4) std::cout << "Copy created: " << m4->getType() << std::endl;
		delete m3;
		delete m4;
	}

	std::cout << "\n========== TEST 6: UNKNOWN MATERIA TYPE ==========" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		
		AMateria* ice_tmp = new Ice();
		src->learnMateria(ice_tmp);
		delete ice_tmp;
		
		std::cout << "\nTrying to create known materia 'ice':" << std::endl;
		AMateria* ice = src->createMateria("ice");
		if (ice)
		{
			std::cout << "Successfully created: " << ice->getType() << std::endl;
			delete ice;
		}
		
		std::cout << "\nTrying to create unknown materia 'fire':" << std::endl;
		AMateria* fire = src->createMateria("fire");
		if (!fire)
			std::cout << "Cannot create 'fire' materia (returns NULL as expected)" << std::endl;
		
		std::cout << "\nTrying to create unknown materia 'lightning':" << std::endl;
		AMateria* lightning = src->createMateria("lightning");
		if (!lightning)
			std::cout << "Cannot create 'lightning' materia (returns NULL as expected)" << std::endl;
		
		delete src;
	}

	std::cout << "\n========== TEST 7: MATERIASOURCE AT CAPACITY ==========" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		
		std::cout << "\nLearning 4 materias (max capacity):" << std::endl;
		AMateria* m1 = new Ice();
		AMateria* m2 = new Cure();
		AMateria* m3 = new Ice();
		AMateria* m4 = new Cure();
		
		src->learnMateria(m1);
		src->learnMateria(m2);
		src->learnMateria(m3);
		src->learnMateria(m4);
		
		delete m1;
		delete m2;
		delete m3;
		delete m4;
		
		std::cout << "\nTrying to learn 5th materia (should be ignored):" << std::endl;
		AMateria* m5 = new Ice();
		src->learnMateria(m5);
		delete m5;
		
		std::cout << "\nCreating materias from full source:" << std::endl;
		AMateria* created1 = src->createMateria("ice");
		AMateria* created2 = src->createMateria("cure");
		if (created1) std::cout << "Created: " << created1->getType() << std::endl;
		if (created2) std::cout << "Created: " << created2->getType() << std::endl;
		delete created1;
		delete created2;
		
		delete src;
	}

	std::cout << "\n========== TEST 8: EQUIP NULL MATERIA ==========" << std::endl;
	{
		ICharacter* test = new Character("Test");
		
		std::cout << "\nTrying to equip NULL materia (should be handled safely):" << std::endl;
		test->equip(NULL);
		
		std::cout << "\nEquipping valid materia after NULL:" << std::endl;
		test->equip(new Ice());
		
		ICharacter* target = new Character("Target");
		test->use(0, *target);
		
		delete target;
		delete test;
	}

	std::cout << "\n========== TEST 9: LEARN NULL MATERIA ==========" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		
		std::cout << "\nTrying to learn NULL materia (should be handled safely):" << std::endl;
		src->learnMateria(NULL);
		
		std::cout << "\nLearning valid materia after NULL:" << std::endl;
		AMateria* ice = new Ice();
		src->learnMateria(ice);
		delete ice;
		
		AMateria* created = src->createMateria("ice");
		if (created)
		{
			std::cout << "Successfully created: " << created->getType() << std::endl;
			delete created;
		}
		
		delete src;
	}

	std::cout << "\n========== TEST 10: MIXED OPERATIONS ==========" << std::endl;
	{
		std::cout << "\nComplex scenario with multiple operations:" << std::endl;
		
		IMateriaSource* src = new MateriaSource();
		AMateria* tmp1 = new Ice();
		AMateria* tmp2 = new Cure();
		src->learnMateria(tmp1);
		src->learnMateria(tmp2);
		delete tmp1;
		delete tmp2;
		
		ICharacter* mage = new Character("Mage");
		ICharacter* knight = new Character("Knight");
		ICharacter* enemy = new Character("Enemy");
		
		// Equip mage
		AMateria* mageSlot0 = src->createMateria("ice");
		mage->equip(mageSlot0);
		mage->equip(src->createMateria("cure"));
		mage->equip(src->createMateria("ice"));
		
		// Equip knight
		knight->equip(src->createMateria("cure"));
		knight->equip(src->createMateria("ice"));
		
		// Battle simulation
		std::cout << "\nMage attacks enemy:" << std::endl;
		mage->use(0, *enemy);
		mage->use(2, *enemy);
		
		std::cout << "\nKnight heals mage:" << std::endl;
		knight->use(0, *mage);
		
		std::cout << "\nMage heals knight:" << std::endl;
		mage->use(1, *knight);
		
		std::cout << "\nKnight attacks enemy:" << std::endl;
		knight->use(1, *enemy);
		
		// Unequip and re-equip
		std::cout << "\nMage unequips slot 0:" << std::endl;
		mage->unequip(0);
		delete mageSlot0; // Delete the unequipped materia
		
		std::cout << "\nMage equips new materia in slot 0:" << std::endl;
		mage->equip(src->createMateria("cure"));
		mage->use(0, *knight);
		
		delete enemy;
		delete knight;
		delete mage;
		delete src;
	}

	std::cout << "\n========== ALL TESTS COMPLETED ==========" << std::endl;
	
	return 0;
}