/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:37:57 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/26 10:01:08 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

class PhoneBook {
private:
	Contact	contacts[8];
	int		nextIndex; /*index where next contact is added*/
	int		count; /*num of added contacts*/

public:
 	PhoneBook();

	bool	addContact();
	bool	searchContacts();
	void	printContact(int index) const;
};

#endif