/*
# R-1.12
Modify the CreditCard class from Code Fragment 1.3 to check that the
price argument passed to function chargeIt and the payment argument
passed to function makePayment are positive.
*/
#include <iostream>
#include <string>
using namespace std;

class CreditCard
{
public:
    CreditCard(const std::string &no,
               const std::string &nm, int lim, double bal = 0);
    
               // accessor functions
    std::string getNumber() const
    {
        return number;
    }
    
    std::string getName() const
    {
        return name;
    }
    
    double getBalance() const
    {
        return balance;
    }
    
    int getLimit() const
    {
        return limit;
    }
    
    bool chargeIt(double price);
    // make a charge
    
    void makePayment(double payment);
    // make a payment
private:
    // private member data
    std::string number;
    // credit card number
    std::string name;
    // card owner’s name
    int
        limit;
    // credit limit
    double
        balance;
    // credit card balance
};

// print card information
std::ostream &operator<<(std::ostream &out, const CreditCard &c);

// standard constructor
CreditCard::CreditCard(const string &no, const string &nm, int lim, double bal)
{
    number = no;
    name = nm;
    balance = bal;
    limit = lim;
}

// make a charge
bool CreditCard::chargeIt(double price)
{
    if ((price < 0) || (price + balance > double(limit)))
        return false;
        
    // over limit
    balance += price;
    return true;
    // the charge goes through
}

void CreditCard::makePayment(double payment)
{ 
    // make a payment
    balance -= payment;
}

// print card information
ostream &operator<<(ostream &out, const CreditCard &c)
{
    out << "Number = "
        << c.getNumber() << "\n"
        << "Name = "
        << c.getName()
        << "\n"
        << "Balance = " << c.getBalance() << "\n"
        << "Limit = "
        << c.getLimit()
        << "\n";
    return out;
}
