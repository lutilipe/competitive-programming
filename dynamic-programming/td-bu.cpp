#include <iostream>
#include <vector>
#include <unordered_map>

#include "assert.h"

using namespace std;

int topDownFib(int n, unordered_map<int, int>& map) {
    if (n <= 1) return n;
    if (map[n]) return map[n];
    map[n] = topDownFib(n-1, map) + topDownFib(n-2, map);
    return map[n];
}

int bottomUPForward(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int bottomUPBackward(int n) {
    vector<int> dp(n+2, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i < n; i++) {
        dp[i+1] += dp[i];
        dp[i+2] += dp[i];
    }
    return dp[n];
}

int main() {
    unordered_map<int, int> map;
    assert(topDownFib(5, map) == 5 && "topDownFib FAIL");
    cout << "Test 1: passed" << endl;
    assert(bottomUPForward(5) == 5 && "bottomUPForward FAIL");
    cout << "Test 2: passed" << endl;
    assert(bottomUPBackward(5) == 5 && "bottomUPBackward FAIL");
    cout << "Test 3: passed" << endl;
    return 0;
}