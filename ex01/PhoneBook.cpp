/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:07:12 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/23 19:08:13 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

PhoneBook::PhoneBook() : nextIndex(0) {}

void PhoneBook::printErrorExit(const char *errorMsg) {
  std::cerr << errorMsg << std::endl;
  exit(EXIT_FAILURE);
}

std::string PhoneBook::getInputStr(const std::string &prompt) {
  std::string userInput;

  while (true) {
    std::cout << prompt;
    if (!std::getline(std::cin, userInput)) {
      if (std::cin.eof())
        printErrorExit("EOF");
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Error: Failed to receive input" << std::endl;
      continue;
    }
    if (!userInput.empty())
      return userInput;
    std::cout << "Empty fields" << std::endl;
  }
}

int PhoneBook::getInputNum() {
  int num;

  while (true) {
    std::cout << "Specify an index: ";
    std::cin >> num;
    if (std::cin.eof())
      printErrorExit("EOF");
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Error: Failed to receive input" << std::endl;
      continue;
    }
    if (num < 0 || num >= MAX_CONTACTS) {
      std::cout << "Error: Invalid index" << std::endl;
      continue;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return num;
  }
}

void PhoneBook::addContact() {
  contacts[nextIndex].setFirstName(getInputStr("First Name: "));
  contacts[nextIndex].setLastName(getInputStr("Last Name: "));
  contacts[nextIndex].setNickname(getInputStr("Nickname: "));
  contacts[nextIndex].setPhoneNumber(getInputStr("Phone Number: "));
  contacts[nextIndex].setDarkestSecret(getInputStr("Darkest Secret: "));
  nextIndex = (nextIndex + 1) % MAX_CONTACTS;
}

void PhoneBook::displayElement(const std::string &str) {
  std::string output =
      (str.length() > WIDTH) ? str.substr(0, WIDTH - 1) + "." : str;
  std::cout << std::setw(WIDTH) << std::right << output << '|';
}

void PhoneBook::displayHeader() {
  std::cout << "|";
  displayElement("index");
  displayElement("first name");
  displayElement("last name");
  displayElement("nickname");
  std::cout << std::endl;
  std::cout << std::string(WIDTH * 4 + 4, '-') << std::endl;
}

void PhoneBook::displayContactList() {
  for (int i = 0; i < MAX_CONTACTS; i++) {
    if (contacts[i].getFirstName().empty()) {
      continue;
    }
    std::cout << "|";
    std::stringstream ss;
    ss << i;
    displayElement(ss.str());
    displayElement(contacts[i].getFirstName());
    displayElement(contacts[i].getLastName());
    displayElement(contacts[i].getNickname());
    std::cout << std::endl;
  }
}

void PhoneBook::displayContact(int index) {
  if (contacts[index].getFirstName().empty()) {
    std::cout << "Error: Contact at index " << index << " does not exist."
              << std::endl;
    return;
  }
  std::cout << "First Name     : " << contacts[index].getFirstName()
            << std::endl;
  std::cout << "Last Name      : " << contacts[index].getLastName()
            << std::endl;
  std::cout << "Nickname       : " << contacts[index].getNickname()
            << std::endl;
  std::cout << "Phone Number   : " << contacts[index].getPhoneNumber()
            << std::endl;
  std::cout << "Darkest Secret : " << contacts[index].getDarkestSecret()
            << std::endl;
}

void PhoneBook::searchContact() {
  if (contacts[0].getFirstName().empty()) {
    std::cout << "Phonebook is currently empty" << std::endl;
    return;
  }
  displayHeader();
  displayContactList();
  displayContact(getInputNum());
}

void PhoneBook::startPhoneBook() {
  std::string cmd;

  while (true) {
    cmd = getInputStr("Command > ");
    if (cmd.compare("ADD") == 0)
      addContact();
    else if (cmd.compare("SEARCH") == 0)
      searchContact();
    else if (cmd.compare("EXIT") == 0)
      exit(EXIT_SUCCESS);
    else
      std::cout << "Error: Invalid command" << std::endl;
  }
}
