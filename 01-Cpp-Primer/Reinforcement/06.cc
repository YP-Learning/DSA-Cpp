/*
# R-1.6 
Consider the following attempt to allocate a 10-element array of pointers
to doubles and initialize the associated double values to 0.0. Rewrite the
following (incorrect) code to do this correctly. (Hint: Storage for the
doubles needs to be allocated.)

    double* dp[10]
    for (int i = 0; i < 10; i++) dp[i] = 0.0;
*/
#include <cstdlib>

int main()
{
    double* dp[10];

    for (int i = 0; i < 10; i++)
        dp[i] = new double(0.0);
}
