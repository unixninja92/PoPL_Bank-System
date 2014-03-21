//Charles Teese
//Principles of Programming Languages
//Term Project Examples

#ifndef __Bank__
#define __Bank__

#include <iostream>
#include "Account.h"
#include <vector>
using namespace std;

typedef vector<Account> accVec;//creates a typedef shortcut for the type vector<Account>


class Bank {//stores lists of clients and open accounts, and allows for transactions to take place
    accVec accounts;//creates a vector using the typedef shortcut of open Accounts at the bank
    int numClients;//number of clients currently at the bank
    int clientListSize;//length of the clients array
    Person **clients;//an array of pointers to pointers of instances of Person
    double *interestRate;//a pointer to an array of intrest rates indexed by AccountType
    
    void expandClientArray();//expands the size of the client array
    
    
    bool clientHasAccount(Person client, AccountType type);//checks to see if the client has an account of the spesified type
    accVec getAccountList();//returns vector of accounts
    Person ** getClientList();//returns the client array
    
    void addAccount(Account newAccount);//opens a new account at the bank
    bool accountExists(Account *acc);//checks to see if a given account is currently open at the bank
    Account removeAccount(Account acc);//closes an account at the bank
    
public:
    Bank();//Initalizes the bank
    ~Bank();//Deconstructs a bank
    
    bool isClient(Person person);//checks to see if a person is a client
    void addClient(Person newClient);//adds a person as a client
    Person removeClient(Person client);//removes a client and thier accounts from the bank system
    
    void addAccount(Person client, AccountType type);//opens a new account of AccountType type for the client
    Account * removeAccount(Person client, AccountType type);//closes one of a clients accounts
    
    double makeDeposit(Person client, AccountType type, double ammount);//makes a deposit in the clients given account
    double makeWithdrawl(Person client, AccountType type, double ammount);//makes a withdrawl from the cliets given account
    double checkBalance(Person client, AccountType type);//checks the balance of the clients given account 
};

#endif /* defined(__Bank_System__Bank__) */
