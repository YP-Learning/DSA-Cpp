/*
# R-1.14 
Modify the CreditCard class from Code Fragment 1.2 to charge a late fee
for any payment that is past its due date.
*/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class CreditCard
{
public:
    CreditCard(const std::string &no,
               const std::string &nm, int lim, double bal = 0, int _dueDay = 0, int _dueMonth = 0, int _dueYear = 0);
    
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
    
    bool chargeIt(double price); // make a charge
    
    void makePayment(double payment); // make a payment
private:
    // private member data
    std::string number; // credit card number
    std::string name; // card owner’s name
    int limit; // credit limit
    double balance; // credit card balance
    static float interetestRate;
    int dueDay, dueYear, dueMonth;
};

// print card information
std::ostream &operator<<(std::ostream &out, const CreditCard &c);

float CreditCard::interetestRate = 0.05f;

// standard constructor
CreditCard::CreditCard(const string &no, const string &nm, int lim, double bal, int _dueDay, int _dueMonth, int _dueYear)
{
    number = no;
    name = nm;
    balance = bal;
    limit = lim;
    dueDay = _dueDay;
    dueMonth = _dueMonth;
    dueYear = _dueYear;
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
    time_t _now = time(NULL);
    struct tm now = *localtime(&_now);
    int latefee = 0;
    if ((now.tm_mday > dueDay) && (now.tm_mon >= (dueMonth - 1)) && (now.tm_year >= (dueYear - 1900)))
        latefee = 100;

    balance -= (payment * (1.0f + interetestRate)) + latefee;
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

int main(const int argc, const char** argv)
{
    CreditCard amex("123456789012", "Yash Pawar", 100000, 10000, 5, 8, 2025);

    std::cout << amex;

    amex.chargeIt(1000);
    amex.makePayment(10000);

    std::cout << amex;

    return (0);
}

