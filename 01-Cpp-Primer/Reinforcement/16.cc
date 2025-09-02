/*
# R-1.16
Modify the declaration of the first for loop in the Test class in Code 
Fragment 1.4 so that its charges will eventually cause exactly one of the three
credit cards to go over its credit limit. Which credit card is it?
*/

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
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
    
    void setLimit(const int _limit)
    {
        limit = _limit;
    }

    void setname(const std::string &_name)
    {
        name = _name;
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

void testCard() { // CreditCard test function
    std::vector<CreditCard*> wallet(10); // vector of 10 CreditCard pointers
    // allocate 3 new cards
    wallet[0] = new CreditCard("5391 0375 9387 5309", "John Bowman", 2500);
    wallet[1] = new CreditCard("3485 0399 3395 1954", "John Bowman", 3500);
    wallet[2] = new CreditCard("6011 4902 3294 2994", "John Bowman", 5000);

    for (int j = 1; j <= 16; j++) { // make some charges
        wallet[0]->chargeIt(double(j)); // explicitly cast to double
        wallet[1]->chargeIt(2 * j); // implicitly cast to double
        wallet[2]->chargeIt(double(40 * j));
    }
    cout << "Card payments:\n";
    
    for (int i=0; i < 3; i++) { // make more charges
        cout << *wallet[i];

        while (wallet[i]->getBalance() > 100.0) {
            wallet[i]->makePayment(100.0);
            cout << "New balance = " << wallet[i]->getBalance() << "\n";
        }

        cout << "\n";
        delete wallet[i]; // deallocate storage
    }
}

int main() { // main function
    testCard();
    return EXIT_SUCCESS; // successful execution
}

