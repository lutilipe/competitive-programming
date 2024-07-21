#include <iostream>

#include <vector>
#include <algorithm> 
using namespace std;

/* 

We have 1, 3, 5 and 10 cents. How many possible ways to coin change of size n?
Ex: n = 4
1 1 1 1
3 1
1 3

Base cases
F(0) = 1 (only one way to return 0)
F(1) = 1 ([1])
F(2) = 1 ([1, 1])
F(3) = 2 ([1, 1, 1], [3]) = F(2) + F(0)
F(4) = 3 ([1, 1, 1, 1], [3, 1], [1, 3]) 
F(5) = 5 ([1, 1, 1, 1, 1], [3, 1, 1], [1, 1, 3], [1, 3, 1], [5])

F(n) = F(n-1) + F(n-3) + F(n-5) + F(n-10) 

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