#include <iostream>

#include <vector>
#include <algorithm> 
using namespace std;

/* 
1)
We have 1, 3, 5 and 10 cents. How many possible ways to coin change of size n, using exactly t coins?

Base cases
F(i, 0) = 0
F(0, 0) = 1
F(i, 1) = 1 if i = {1,3,5,10}, 0 others

F(n, t) = F(n-1, t-1) + F(n-3,t -1) + F(n-5, t-1) + F(n-10, t-1) 

*/

int res1(int n, int t) {
    vector<vector<int>> dp(n+1, vector<int>(t+1, 0));

    int coins[4] = {1, 2, 3, 5};

    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            if (i > 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }
            for (int k = 0; k < 4; k++) {
                if (i-coins[k] < 0) break;
                dp[i][j] += dp[i-coins[k]][j-1];
            }
        }
    }
    return dp[n][t];
}

/* 

2) We have 1, 3, 5 and 10 cents. How many possible ways to coin change of size n, using no more than t coins?

Considering x = 1 if is even, and 0 if is odd;

F(i, x)

Base cases
F(i, 0) = 0
F(0, 0) = 1 
F(i, 1) = 1 if i = {0, 1,3,5,10}, 0 others. 0 enters because it's "no more than"

F(n, t) = F(n-1, t-1) + F(n-3,t -1) + F(n-5, t-1) + F(n-10, t-1) 

*/

int res2(int n, int t) {
    vector<vector<int>> dp(n+1, vector<int>(t+1, 0));

    int coins[4] = {1, 2, 3, 5};

    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            if (i > 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if (i == 0 && j > 0) {
                dp[i][j] = 1;
                continue;
            }

            for (int k = 0; k < 4; k++) {
                if (i-coins[k] < 0) break;
                dp[i][j] += dp[i-coins[k]][j-1];
            }
        }
    }
    return dp[n][t];
}

/* 

3) We have 1, 3, 5 and 10 cents. How many possible ways to coin change of size n, using an even number of coins?

Considering x = 1 if is even, and 0 if is odd;

F(i, x)

Base cases
F(0,0) = 0;
F(0, 1) = 1
F(1, 1) = 1 (There is a coin of value 1)
F(2, 0) = 0 (There is no coin of value 2)
F(2, 1) = 1 ([1,1])
F(3, 0) = 2 ([1,1,1], [3])
F(3, 1) = 0
F(4, 0) = 0
F(4, 1) = 2 ([3,1], [1,3])
F(5, 0) = 3
F(5, 1) = 0

X = 0 (odd) => F(i, 0) = F(i-1, 1) + F(i-3, 1) ... (if we subtract 1 from and odd number, it becomes even)
X = 1 (even) => F(i, 1) = F(i-1, 0) + F(i-3, 0) ... (if we subtract 1 from and even number, it becomes odd)

*/

int res3(int n) {
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    int coins[4] = {1, 3, 5, 10};

    dp[0][0] = 0;
    dp[0][1] = 1;

    for (int i = 0; i <= n; i++) {
        for (int k = 0; k < 4; k++) {
            if (i-coins[k] < 0) break;
            dp[i][0] += dp[i-coins[k]][1];
            dp[i][1] += dp[i-coins[k]][0];
        }
    }
    return dp[n][!(n%2)];
}

int main() {
    cout << res1(7,3) << endl;
    cout << res2(7,3) << endl;
    cout << res3(6) << endl;
    return 0;
}