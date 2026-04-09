/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:42:08 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/26 09:53:48 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();

	//Getters
	std::string getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickName(void) const;
	std::string	getPhoneNum(void) const;
	std::string	getSecret(void) const;

	//Setters
	void	setFirstName(const std::string &first);
	void	setLastName(const std::string &last);
	void	setNickName(const std::string &nick);
	void	setPhoneNum(const std::string &phone);
	void	setSecret(const std::string &secret);

};

#endif