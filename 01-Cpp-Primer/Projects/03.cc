/*
# P-1.3
The birthday paradox says that the probability that two people in a room
will have the same birthday is more than half as long as the number of
people in the room (n), is more than 23. This property is not really a paradox, 
but many people find it surprising. Design a C++ program that can
test this paradox by a series of experiments on randomly generated birthdays, 
which test this paradox for n = 5,10,15,20,...,100. You should run
at least 10 experiments for each value of n and it should output, for each
n, the number of experiments for that n, such that two people in that test
have the same birthday.
*/

#include <iostream>
#include <unordered_set>
#include <ctime>

int birthdayParadox(int n)
{
    int bdays[n];
    std::unordered_set<int> uniqueBdays;

    for (int i = 0; i < n; i++)
    {
        bdays[i] = rand() % 365;
        uniqueBdays.insert(bdays[i]);
    }

    return (n - uniqueBdays.size());
}

int main(int argc, char const *argv[])
{
    int n, noSameBdays, nExp = 10000;

    // std::cout << "Enter n: ";
    // std::cin >> n;

    srand(time(NULL));

    for (int n = 1; n <= 50; n++)
    {
        int c = 0;
        for (int i = 0; i < nExp; i++)
        {
            noSameBdays = birthdayParadox(n);
            // std::cout << "Experiment " << i + 1 << " no of same bdays: " << noSameBdays << std::endl;
            if (noSameBdays > 0)
                c++;
        }

        std::cout << "For n = " << n << " Probability is " << (((float)c / (float)nExp) * 100.0f) << "%" << std::endl;
    }

    return 0;
}

