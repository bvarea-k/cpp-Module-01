/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:13:16 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/19 16:26:18 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

/*Character owns the inventory and manages the lifetime of the Materias.
ICharacter only defines the interface.*/

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria* _inventory[4];
	
	public:
		Character(std::string const & name);
		Character(Character const & other);
		Character & operator=(Character const & other);
		virtual ~Character();
	
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
