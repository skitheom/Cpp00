/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:47:00 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/23 19:08:07 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(int argc, const char **argv) {
  (void)argv;
  if (argc != 1) {
    std::cerr << "Error: too many arguments" << std::endl;
    return 1;
  }
  PhoneBook phoneBook;
  phoneBook.startPhoneBook();
  return 0;
}
