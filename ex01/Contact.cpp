/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:45:11 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/23 19:07:49 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
    : firstName(""), lastName(""), nickname(""), phoneNumber(""),
      darkestSecret("") {}

Contact::Contact(const std::string &first, const std::string &last,
                 const std::string &nick, const std::string &phone,
                 const std::string &secret)
    : firstName(first), lastName(last), nickname(nick), phoneNumber(phone),
      darkestSecret(secret) {}

void Contact::setFirstName(const std::string &first) { firstName = first; }
void Contact::setLastName(const std::string &last) { lastName = last; }
void Contact::setNickname(const std::string &nick) { nickname = nick; }
void Contact::setPhoneNumber(const std::string &phone) { phoneNumber = phone; }
void Contact::setDarkestSecret(const std::string &secret) {
  darkestSecret = secret;
}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }
