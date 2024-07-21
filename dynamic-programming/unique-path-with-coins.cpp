#include <iostream>

#include <vector>
#include <algorithm> 
#include <math.h> 
using namespace std;

/* 

We can only turn right or down. How many unique paths it have?
+---+---+---+---+
| S | 2 | 2 | 1 |
+---+---+---+---+
| 3 | 1 | 1 | 1 |
+---+---+---+---+
| 4 | 4 | 2 | E |
+---+---+---+---+ n x m

F(n,m) = max(F(n-1, m) + F(n, m-1))

*/

void getPath(vector<vector<int>>& dp, int i, int j, vector<vector<int>>& path) {
    if (i == 0 && j == 0) {
        path.push_back({0, 0});
        return;
    };
    if (i == 0) {
        getPath(dp, i, j-1, path);
    } else if (j == 0) {
        getPath(dp, i-1, j, path);
    } else {
        if (dp[i][j-1] > dp[i-1][j]) {
            getPath(dp, i, j-1, path);
        } else {
            getPath(dp, i-1, j, path);
        }
    }
    path.push_back({i,j});
}

int res(vector<vector<int>> grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = grid[i][j];
            if (j - 1 >= 0 && i - 1 >= 0) {
                dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
            } else if (j - 1 >= 0) {
                dp[i][j] += dp[i][j-1];
            } else if (i - 1 >= 0) {
                dp[i][j] += dp[i-1][j];
            }
        }
    }

    vector<vector<int>> path;
    getPath(dp, m-1, n-1, path);

    for (int i = 0; i < path.size(); i++) {
        cout << path[i][0] << ", " << path[i][1] << endl;
    }

    return dp[m-1][n-1];
}

int main() {
    cout << res({
        {0, 2, 2, 1},
        {3, 1, 1, 1},
        {4, 4, 2, 0},
    }) << endl;
    
    return 0;
}