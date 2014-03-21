//Charles Teese
//Principles of Programming Languages
//Term Project Examples

#ifndef __Account__
#define __Account__

#include <string>

using namespace std;

class Account;//states that Account is a class that will later be defined    

enum AccountType //creates an enum type called AccountType that can either be Checking or Savings.
{
	Checking = 0,
	Savings = 1
};

struct Person//stores information about a person including their name, their accounts with this bank, and their position in the banks client list
{
	string lastName, firstName;//persons name
	Account **accounts;//a pointer to an array of pointers where each pointer in the array is pointing to an account belonging to this person
    int clientNum; //Person's position in the banks client list
    
    Person(string first, string last) : accounts(new Account*[2]) {//inatalizes struct with persons name and creates a pointer array of size two to store checking and savings accounts
        lastName = last;
        firstName = first;
        accounts[Savings] = 0;//sets the pointer to the persons savings account to null
        accounts[Checking] = 0;//sets the pointer to the persons checking account to null
    }
    Person() :accounts(new Account*[2]) {//same as above but without initalizing persons name
        accounts[Savings] = 0;
        accounts[Checking] = 0;
    }
    
};

class Account
{
	Person accountHolder;//person who owns the account
	AccountType type;//type of account it is (savings or checking)
	double balance;//what the balance in the account is
	int accountNumber;
	static int nextAccountNum;//static int shared between all instances of Account that keeps track of the next avalible account number
public:
 	Account(Person holder, AccountType typ, double ball = 0);//Constructs account with a default balance of 0
    ~Account();//deconstructs account
 	Person getAccountHolder();//returns account holder
 	AccountType getAccountType();//returns account type
 	double getBalance();//returns balance in account
 	int getAccountNumber();//returns account number
 	void changeBalance(double newBalance);//changes the account's balance 
};

#endif