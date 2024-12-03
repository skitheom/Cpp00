/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:08:17 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/23 19:08:18 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
  static const int WIDTH = 10;
  static const int MAX_CONTACTS = 8;
  Contact contacts[MAX_CONTACTS];
  int nextIndex;

  void printErrorExit(const char *errorMsg);
  std::string getInputStr(const std::string &prompt);
  int getInputNum();
  void addContact();
  void displayElement(const std::string &element);
  void displayHeader();
  void displayContactList();
  void displayContact(int index);
  void searchContact();

public:
  PhoneBook();
  void startPhoneBook();
};

#endif
