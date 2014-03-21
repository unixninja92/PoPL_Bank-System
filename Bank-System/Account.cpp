//Charles Teese
//Principles of Programming Languages
//Term Project Examples

#include "Account.h"
#include <iostream>

int Account::nextAccountNum = 1;//starts Account numbers at one

Account::Account(Person holder, AccountType typ, double ball){//initalizes an account
    type = typ;
	accountNumber = nextAccountNum++;//the account number is set to the current value of nextAccountNum and nextAccountNum is then increased by 1
	accountHolder = holder;
    accountHolder.accounts = new Account*[2];//creates an array of pointers to Accounts
	balance = ball;
}

Account::~Account(){//Deconstructs an account 
    accountHolder.accounts[type] = 0;
}

Person Account::getAccountHolder(){
    return accountHolder;
}

AccountType Account::getAccountType(){
    return type;
}

double Account::getBalance(){
    return balance;
}

int Account::getAccountNumber(){
    return accountNumber;
}

void Account::changeBalance(double newBalance){
    balance = newBalance;
}