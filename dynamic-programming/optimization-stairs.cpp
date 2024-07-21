#include <iostream>

#include <vector>
using namespace std;

/* 

F(n) = P(n) + min(P(n-1) + P(n-2));

*/

int main() {
    int n = 3, k = 2;
    vector<int> prices = {3, 2, 4};
    vector<int> dp(n + 1 , 0);
    dp[0] = 0;
    dp[1] = prices[0];
    for (int i = 2; i <= n; i++) {
        dp[i] = prices[i] + min(prices[i - 1], prices[i - 2]);
    }
    cout << dp[n] << endl; 
    return 0;
}