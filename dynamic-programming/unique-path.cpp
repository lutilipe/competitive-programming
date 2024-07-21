#include <iostream>

#include <vector>
#include <algorithm> 
using namespace std;

/* 

We can only turn right or down. How many unique paths it have?
+---+---+---+
| S |   |   |
+---+---+---+
|   |   |   |
+---+---+---+
|   |   | E |
+---+---+---+ n x m

F(n,m) = F(n-1, m) + F(n, m-1)

*/

int main() {
    int n = 3;
    int m = 3;
    vector<vector<int>> dp(m, vector<int>(n, 1));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j - 1 >= 0 && i - 1 >= 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            } else if (j - 1 >= 0) {
                dp[i][j] = dp[i][j-1];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[m-1][n-1] << endl;
    return 0;
}