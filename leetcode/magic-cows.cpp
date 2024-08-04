#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

int magicCows(int C, int N, int M, vector<int> cows) {
    vector<vector<int>> dp(M+1, vector<int>(C+1, 0));
    for (int i = 0; i < N; i++) {
        dp[0][cows[i]]++;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= C; j++) {
            if (j*2 <= C) {
                dp[i+1][j*2] += dp[i][j];
            } else {
                dp[i+1][j] += dp[i][j] * 2;
            }
        }
    }

    int sum = 0;
    for (int i : dp[M]) {
        sum+=i;
    }
    return sum;
}

/* 

[0, 0, 0, 0, 0, 0, 0, 0];

 1  2  3  4  5  6  7  8 
[2, 1, 1, 0, 0, 0, 0, 0];
[0, 2, 0, 1, 0, 1, 0, 0];
[0, 0, 0, 2, 0, 2, 0, 1];
[0, 0, 0, 0, 0, 4, 0, 4];
[0, 0, 0, 0, 0, 8, 0, 8];

if (j*2 < 8(C)) {
    dp[i+1, j*2] = d[i,j];
} else {
    dp[i+1,j] = dp[i,j]*2
}

*/

int main() {
    vector<int> cows = {1,3,2,1};
    cout << magicCows(8,4,4,cows) << endl;
    return 0;
}