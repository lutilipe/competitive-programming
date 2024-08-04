#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int lcs(int m, int n, string& s1, string& s2, vector<vector<int>>& memo) {
    if (m == 0 || n == 0) return 0;
    if (memo[m][n] != -1) return memo[m][n];
    if (s1[m-1] == s2[n-1]) {
        memo[m][n] = 1 + lcs(m-1, n-1, s1, s2, memo);
    } else {
        memo[m][n] = max(lcs(m-1, n, s1, s2, memo), lcs(m, n-1, s1, s2, memo));
    }
    return memo[m][n];
}


int main() {
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    int m = S1.size();
    int n = S2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

    cout << "Length of LCS is " << lcs(m, n, S1, S2, dp);

    return 0;
}
