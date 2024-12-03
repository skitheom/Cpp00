/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:45:04 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/21 19:45:05 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;

public:
  Contact();
  Contact(const std::string &first, const std::string &last,
          const std::string &nick, const std::string &phone,
          const std::string &secret);

  void setFirstName(const std::string &first);
  void setLastName(const std::string &last);
  void setNickname(const std::string &nick);
  void setPhoneNumber(const std::string &phone);
  void setDarkestSecret(const std::string &secret);

  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getNickname() const;
  std::string getPhoneNumber() const;
  std::string getDarkestSecret() const;
};

#endif
