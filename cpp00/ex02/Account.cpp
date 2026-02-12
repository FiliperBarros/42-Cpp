#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit)
{

	_nbAccounts += 1;
	_totalAmount += initial_deposit;

	this->_accountIndex = _nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;

}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return(_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";

	this->_amount += deposit;
	this->_nbDeposits += 1;

	_totalAmount += deposit;
	_totalNbDeposits += 1;

	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;

}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";

	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (0);
	}

	this->_amount-= withdrawal;
	this->_nbWithdrawals += 1;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;

	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (1);
}


void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
						<< "total:" << getTotalAmount()<< ";"
						<< "deposits:" << getNbDeposits()<< ";"
						<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t	now = time(0);
	struct tm *lcltime = localtime(&now);

	std::cout << "[";
	
	std::cout << 1900 + lcltime->tm_year;
	
	if (1 + lcltime->tm_mon < 10)
		std::cout << "0";
	std::cout << 1 + lcltime->tm_mon;
	
	if (lcltime->tm_mday < 10)
		std::cout << "0";
	std::cout << lcltime->tm_mday;

	std::cout << "_";

	if (lcltime->tm_hour < 10)
		std::cout << "0";
	std::cout << lcltime->tm_hour;
	
	
	if (lcltime->tm_min < 10)
		std::cout << "0";
	std::cout << lcltime->tm_min;
	
	if (lcltime->tm_sec < 10)
		std::cout << "0";
	std::cout << lcltime->tm_sec;

	std::cout << "] ";
}