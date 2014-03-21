//Charles Teese
//Principles of Programming Languages
//Term Project Examples

#include <iostream>
#include "Account.h"
#include "Bank.h"

int main(int argc, const char * argv[])
{
    Person bob = *new Person("Jim", "Bob");
    Person phil = *new Person("Phil", "Patterson");
    Person guy  = *new Person("That", "Guy");
    
    Bank *firstNational = new Bank();
    
    firstNational->addClient(bob);
    firstNational->addAccount(bob, Savings);
    firstNational->addAccount(bob, Checking);
    
    firstNational->addClient(phil);
    firstNational->addAccount(phil, Checking);
    
    firstNational->addClient(guy);
    firstNational->addAccount(guy, Savings);
    
    firstNational->makeDeposit(guy, Savings, 2);
    firstNational->makeDeposit(bob, Checking, 1000.01);
    

    //my removeal functions do not seem to be doing exactly what they are 
//    firstNational->removeAccount(bob, Savings);
//    
//    firstNational->removeClient(phil);
    
    firstNational->makeWithdrawl(bob, Checking, 200);
    
    cout << firstNational->checkBalance(guy, Savings);
    cout << '\n';
    cout << firstNational->isClient(phil);
    return 0;
}

