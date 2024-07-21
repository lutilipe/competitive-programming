#include <iostream>

#include <vector>
#include <algorithm> 
#include <limits.h> 
using namespace std;

/* 

Minimum number of coins to make a change
N = 4 => 2 (the minimum is using 1 and 3) 

Coins: 1 3 5

F(0) = 0
F(1) = 1
F(2) = 2
F(3) = 1
F(4) = 2
F(5) = 1
F(6) = 2
F(7) = 3
F(8) = 2

F(n) = min(F(i-1), F(i-3), F(i-5)) + 1

*/

int res(int n) {
    vector<int> dp(n+1, 0);

    int coins[3] = {1, 3, 5};

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < 3; j++) {
            if (i < coins[j]) break;
            dp[i] = min(dp[i-coins[j]], dp[i]) + 1;
        }
    }
    return dp[n];
}

int main() {
    cout << res(7) << endl;
    return 0;
}