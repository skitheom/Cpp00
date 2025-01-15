/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:37:15 by sakitaha          #+#    #+#             */
/*   Updated: 2025/01/15 18:54:24 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
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
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  _amount += deposit;
  _nbDeposits++;
  _totalAmount += deposit;
  _totalNbDeposits++;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex;
  std::cout << ";p_amount:" << _amount - deposit;
  std::cout << ";deposit:" << deposit;
  std::cout << ";amount:" << _amount;
  std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {

  _displayTimestamp();
  std::cout << " index:" << _accountIndex;
  std::cout << ";p_amount:" << _amount;
  if (_amount < withdrawal) {
    std::cout << ";withdrawal:refused" << std::endl;
    return false;
  }
  _amount -= withdrawal;
  _nbWithdrawals++;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;
  std::cout << ";withdrawal:" << withdrawal;
  std::cout << ";amount:" << _amount;
  std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
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

void Account::_displayTimestamp(void) {

#ifdef ACCOUNT_USE_FIXED_TIMESTAMP
  std::cout << "[19920104_091532]";
  return;
#endif

  const int BUFFER_SIZE = 42;
  char buf[BUFFER_SIZE];
  std::time_t timestamp = std::time(0);
  std::tm *timePtr = std::localtime(&timestamp);

  std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", timePtr);
  std::cout << buf;
}

Account::Account(void) {}
