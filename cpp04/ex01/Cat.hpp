/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:05:48 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/19 12:26:33 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
class Cat : public Animal {
	private:
		Brain *_brain;

	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();
		
		void makeSound() const;
		bool addIdea(std::string idea);
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
};

#endif