/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:52:54 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/12/19 12:32:47 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
 #define BRAIN_HPP

 # include <iostream>
 
class Brain {
	private:
		std::string _ideas[100];;
		
	public:
		Brain();
		Brain(std::string type);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

		bool addIdea(std::string idea);
		std::string getIdea(int index);
		void setIdea(int index, std::string idea);
};

#endif