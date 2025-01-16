/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:29:39 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/17 02:09:17 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static void print_to_upper(const char *str) {
  if (!str) {
    return;
  }
  for (int i = 0; str[i]; i++) {
    std::cout << static_cast<char>(std::toupper(str[i]));
  }
}

int main(int argc, const char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
  }
  for (int i = 1; i < argc; i++) {
    print_to_upper(argv[i]);
  }
  std::cout << std::endl;
  return (0);
}
