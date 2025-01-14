/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:37:15 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/15 08:35:57 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << " accounts:" << _nbAccounts;
  std::cout << ";total:" << _totalAmount;
  std::cout << ";deposits:" << _totalNbDeposits;
  std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
  _nbAccounts++;
  _totalAmount += initial_deposit;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";created" << std::endl;

  (void)_nbDeposits;
  (void)_nbWithdrawals;
}

Account::~Account(void) {}

void Account::makeDeposit(int deposit) {
  _amount += deposit;
  _nbDeposits++;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex;
  std::cout << ";p_amount:" << _amount - deposit;
  std::cout << ";deposit:" << deposit;
  std::cout << ";amount:" << _amount;
  std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

/*
19920104_091532] index:0;p_amount:47;withdrawal:refused
[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
[19920104_091532]
index:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1
[19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
[19920104_091532]
index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
[19920104_091532] index:5;p_amount:23;withdrawal:refused
[19920104_091532]
index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1
[19920104_091532]
index:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1

        std::time_t	timestamp = std::time(NULL);
        std::tm		*local_time = std::localtime(&timestamp);
        char		time_buffer[20];

        std::strftime(time_buffer, sizeof(time_buffer), "[%Y%m%d_%H%M%S] ",
local_time); std::cout << time_buffer;
 */

bool Account::makeWithdrawal(int withdrawal) {
  std::cout << "Calling... makeWithdrawal" << std::endl;
  (void)withdrawal;
  return true;
}
int Account::checkAmount(void) const {
  std::cout << "Calling... checkAmount" << std::endl;
  return 0;
}
void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";deposits:" << _nbDeposits;
  std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) { std::cout << "[%Y%m%d_%H%M%S]"; }

Account::Account(void) {
  std::cout << "Calling... Account(void) " << std::endl;
}
