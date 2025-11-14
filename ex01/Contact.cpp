/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:42:03 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/14 15:52:08 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

// Individual setters
void Contact::setFirstName(const std::string &first) { firstName = first; }
void Contact::setLastName(const std::string &last) { lastName = last; }
void Contact::setNickName(const std::string &nick) { nickName = nick; }
void Contact::setPhoneNum(const std::string &phone) { phoneNumber = phone; }
void Contact::setSecret(const std::string &secret) { darkestSecret = secret; }

// Getters
std::string Contact::getFirstName(void) const { return firstName; }
std::string Contact::getLastName(void) const { return lastName; }
std::string Contact::getNickName(void) const { return nickName; }
std::string Contact::getPhoneNum(void) const { return phoneNumber; }
std::string Contact::getSecret(void) const { return darkestSecret; }
