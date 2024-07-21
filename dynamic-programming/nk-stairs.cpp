#include <iostream>

#include <vector>
using namespace std;

int main() {
    int n = 0, k = 0;
    while (cin >> n >> k) {
        vector<int> dp(k , 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < k; j++) {
                if (i - j < 0) break;
                dp[i%k] += dp[(i-j)%k];
            }
        }
        cout << dp[n%k] << endl; 
    }
    return 0;
}