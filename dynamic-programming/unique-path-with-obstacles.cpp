#include <iostream>

#include <vector>
#include <algorithm> 
using namespace std;

/* 

We can only turn right or down. How many unique paths it have?
+---+---+---+---+
| S |   |   |   |
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
|   | 1 | 1 | 1 |
+---+---+---+---+
|   |   | E |   |
+---+---+---+---+ n x m

F(n,m) = F(n-1, m) + F(n, m-1)

*/

int res(vector<vector<int>> grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                dp[i][j] = 0;
                continue;
            }
            if (j - 1 >= 0 && i - 1 >= 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            } else if (j - 1 >= 0) {
                dp[i][j] = dp[i][j-1];
            } else if (i > 0 ) {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[m-1][n-1];
}

int main() {
    cout << res({
        {0, 0, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 0},
    }) << endl;
    
    return 0;
}