// Scrambled String (Recursive): https://www.geeksforgeeks.org/check-if-a-string-is-a-scrambled-form-of-another-string/

#include<bits/stdc++.h>
using namespace std;

bool solve(string X, string Y)
{
    if(X.compare(Y) == 0)
        return true;
    
    if(X.length() <= 1)
        return false;
    
    int n = X.length();
    int flag = false;

    for(int i = 1; i <= n - 1; i++)
    {   
        // Case 1: When the strings are swapped at i
        bool case1 = solve(X.substr(0, i), Y.substr(n - i, i)) && solve(X.substr(i), Y.substr(0, n - i));

        // Case 2: When the strings are not swapped at i
        bool case2 = solve(X.substr(0, i), Y.substr(0, i)) && solve(X.substr(i), Y.substr(i));

        if(case1 || case2)
        {
            flag = true;
            break;
        }
    }

    return flag;
}

int main()
{
    string X, Y;
    cin >> X >> Y;

    if(X.length() != Y.length())
        cout << false << "\n";
    
    else 
        cout << solve(X, Y) << "\n";

    return 0;
}