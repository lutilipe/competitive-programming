#include <iostream>

#include <vector>
#include <algorithm> 
using namespace std;

/* 

We have 1, 2, 3 and 5 cents. How many possible unique ways to coin change of size n?
Ex: n = 4
1 1 1 1
3 1
1 3

Last two are not unique, so we have to choose the most preferrable. Ex: the one that
has a non-increasing order.

We can add a constraint so that the last coin is less than t (non-increasing order)
F(i, t) => t is the last coin we are allow to use

Base cases
F(0, 0) = 1
F(i, 0) = 0
F(1,1) = 1
F(2, 1) = 1 
F(2, 2) = 1 

*/

int res(int n) {
    vector<int> dp(n+1, 0);

    int coins[4] = {1, 3, 5, 10};

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            if (i < coins[j]) break;
            dp[i] += dp[i-coins[j]];
        }
    }
    return dp[n];
}

int main() {
    cout << res(5) << endl;
    return 0;
}