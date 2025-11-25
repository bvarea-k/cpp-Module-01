/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:22:28 by bvarea-k          #+#    #+#             */
/*   Updated: 2025/11/25 09:21:07 by bvarea-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;			//Inicializo las variables static de private
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*Defino el ¿constructor? Recibe el depósito inicial,
así que debe llamarse cuando creo una cuenta nueva*/

Account::Account( int initial_deposit ){
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts++;							//Al crear otra cuenta, aumenta el n. de cuentas total
	Account::_totalAmount += initial_deposit;		//Añado al total del dinero de todas las cuentas

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";created" << std::endl;
}

Account::~Account()									//Destructor
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed" << std::endl;
}

void	Account::_displayTimestamp( void ) {
	time_t currentTime = time(NULL);			//time_t guarda el tiemop en segundos. time(NULL)devuelve el tiempo actual en segundos desde el 1 de enero de 1970
	//ahora currentTime tiene el tiempo actual en segundos
	struct tm *timeInfo = localtime(&currentTime);  //estructura de la librerá ctime. Almacena la info de fecha y hora desglosada
	char buffer[16];							//16 para los 15 que necesito y el \0 final

	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeInfo); //strftime convierte tm en un string
	std::cout << "[" << buffer << "] ";			//imprime el tiempo entre corchetes
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
	return (Account::_nbAccounts); //¿Debo poner Account:: o funcionará sin?
}

int	Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
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
	std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	std::cout << ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits
  				<< std::endl;			
}

bool	Account::makeWithdrawal( int withdrawal ){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount;

	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal
				<< ";amount:" << this->_amount
				<< ";nb_withdrawals:" << this->_nbWithdrawals
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