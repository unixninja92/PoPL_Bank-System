//Charles Teese
//Principles of Programming Languages
//Term Project Examples

#ifndef BankExceptions_h
#define BankExceptions_h

#include <exception>
namespace exceptions{
    
    class ClientNotFoundException : public std::exception {
        virtual const char* what() const throw() {
            return "This person is not a client of this bank.";
        }
    };
    
    class AlreadyAClientException : public std::exception {
        virtual const char* what() const throw() {
            return "This person is already a client of this bank.";
        }
    };


    class AccountNotFoundException : public std::exception {
        virtual const char* what() const throw() {
            return "This account does not exist";
        }
    };
    
    class AccountAlreadyExistsException : public std::exception {
        virtual const char* what() const throw() {
            return "This account already exists";
        }
    };

}

#endif
