/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:22:28 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/25 10:12:40 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){
	_accountIndex = Account::_nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed" << std::endl;
}

void	Account::_displayTimestamp( void ) {
	time_t currentTime = time(NULL);			//time_t guarda el tiemop en segundos. time(NULL)devuelve el tiempo actual en segundos desde el 1 de enero de 1970
	//ahora currentTime tiene el tiempo actual en segundos
	struct tm *timeInfo = localtime(&currentTime);  //estructura de la librerá ctime. Almacena la info de fecha y hora desglosada
	char buffer[16];							//16 para los 15 que necesito y el \0 final

	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeInfo); //strftime convierte tm en un string
	std::cout << "[" << buffer << "] ";
}

/*void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *ltm = std::localtime(&now);

	std::cout << "["
				<< (ltm->tm_year + 1900)
				<< std::setw(2) << std::setfill('0') << ltm->tm_mon + 1
				<< std::setw(2) << std::setfill('0') << ltm->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0') << ltm->tm_hour
				<< std::setw(2) << std::setfill('0') << ltm->tm_min
				<< std::setw(2) << std::setfill('0') << ltm->tm_sec
				<< "] ";
}*/

int	Account::getNbAccounts( void ){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
				<< ";total:" << Account::getTotalAmount()
				<< ";deposits:" << Account::getNbDeposits()
				<< ";withdrawals:" << Account::getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit( int deposit ){
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	std::cout << ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
  				<< std::endl;			
}

bool	Account::makeWithdrawal( int withdrawal ){
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount;

	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;

	return (true);
}

int	Account::checkAmount( void ) const{
	return (_amount);
}

void	Account::displayStatus( void ) const{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}