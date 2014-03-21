//Charles Teese
//Principles of Programming Languages
//Term Project Examples

#include <iostream>
#include "BankExceptions.h"
#include "Bank.h"


Bank::Bank()
{
    numClients = 0;
    clientListSize = 1;
    clients = new Person*[numClients];
    interestRate = new double[2];
    interestRate[Savings] = .1;
    interestRate[Checking] = .01;
}
Bank::~Bank(){
//    delete clients;
    delete interestRate;
}

void Bank::expandClientArray(){
    Person **newClients = new Person*[clientListSize*2];//create new array of double the size
    int i = 0;
    while (i < numClients) { //add clients to the new array
        newClients[i] = clients[i];
        i++;
    }
    clientListSize *= 2;
    clients = newClients; //point clinets to the new array
//    cout << clients << '\n' << newClients;
}

Person ** Bank::getClientList(){
    return clients;
}

accVec Bank::getAccountList(){
    return accounts;
}


bool Bank::clientHasAccount(Person client, AccountType type){
    if(isClient(client) && client.accounts[type] != 0){
        return true;
    }
    return false;
}

bool Bank::isClient(Person person){
    for(int i = 0; i < numClients; i++){//goes through the client array checking to see if person is in the array
        if(clients[i]->firstName == person.firstName && clients[i]->lastName == person.lastName){
            return true;
        }
    }
    return false;
}


void Bank::addClient(Person newClient){
    if(!isClient(newClient)){
        newClient.clientNum = ++numClients;//incraments numClinets by 1 and then sets the new clients number(position in the array) to numClinets
        if(numClients >= clientListSize)//if we have filled the array with clients, then expand the size of the array
            expandClientArray();
        clients[numClients-1] = &newClient;//adds the memory address of the new client to the array of clients(really of pointers to clients)
    }
    else
        throw exceptions::AlreadyAClientException();
}

Person Bank::removeClient(Person client){
    if(isClient(client)){
        if(clientHasAccount(client, Checking))//removes clients checking account if it exists
            removeAccount(client, Checking);
        if(clientHasAccount(client, Savings))//removes clients savings account if it exists
            removeAccount(client, Savings);
        int pos = client.clientNum;
        for(int i = pos; i < numClients-1; i++){//moves the clients down the array, thus remvoing the current client
            clients[i] = clients[i+1];
            clients[i]->clientNum--;
        }
        numClients--;
    }
    else
        throw exceptions::ClientNotFoundException();
    return client;//returns the removed client
}

bool Bank::accountExists(Account *acc){
    if(acc != 0){
        for(int i = 0; i < accounts.size(); i++){//goes through the account vector to see if the given account is in there
            if(accounts[i].getAccountNumber() == acc->getAccountNumber()){
                return true;
            }
        }
    }
    return false;
}


void Bank::addAccount(Account newAccount){
    if(!accountExists(&newAccount)){
        accounts.push_back(newAccount);//pushes the new account to the back of the vector
    }
    else
        throw exceptions::AccountAlreadyExistsException();
}


void Bank::addAccount(Person client, AccountType type){
    if(isClient(client)){
        addAccount(*new Account(client, type));//adds the account to the account vecotr
        client.accounts[type] = &accounts.back();//adds account the the clients account array
    }
    else
        throw exceptions::ClientNotFoundException();
}

Account Bank::removeAccount(Account acc){
    if(accountExists(&acc)){
        for(int i = 0; i<accounts.size(); i++){//searches for account in queston
            if(accounts[i].getAccountNumber() == acc.getAccountNumber()){
//                cout << '\n' << acc.getAccountNumber()<< '\n';
                swap(accounts[i], accounts.back());//swaps the account to be removed with the account on the end of the vector.
                accounts[i].getAccountHolder().accounts[accounts[i].getAccountType()] = &accounts[i];//sets the account holders accounts array to be correct
                accounts.pop_back();//removes the last item from the vector, which is the account to be removed
                break;//breaks out of the for loop
            }
        }
    }
    else
        throw exceptions::AccountNotFoundException();
    
    return acc;
}


Account * Bank::removeAccount(Person client, AccountType type){
    if(isClient(client)){
        Account *acc = client.accounts[type];//makes a temporay copy of the account
        if(accountExists(acc)){
            removeAccount(*acc);//removes the accout from the acount list
            client.accounts[type] = 0;//sets clients accounts array to accuratley relflect the changes
            return acc;//return the removed account
        }
        else
            throw exceptions::AccountNotFoundException();
    }
    throw exceptions::ClientNotFoundException();
}

double Bank::makeDeposit(Person client, AccountType type, double ammount){
    Account &acc = *client.accounts[type];//creates a referance to the account
    acc.changeBalance(acc.getBalance()+ammount);//increases the accounts balance
    return acc.getBalance();//returns the new balance
}

double Bank::makeWithdrawl(Person client, AccountType type, double ammount){
    Account &acc = *client.accounts[type];//creates a referance to the account
    acc.changeBalance(acc.getBalance()-ammount);//decreases the accounts balance
    return acc.getBalance();//returns the new balance
}

double Bank::checkBalance(Person client, AccountType type){
    if (isClient(client)){
        if(accountExists(client.accounts[type]))
            return client.accounts[type]->getBalance();//returns specified accounts balance 
        else throw exceptions::AccountNotFoundException();
    }
    throw exceptions::ClientNotFoundException();
    
}