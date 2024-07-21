#include <iostream>

#include <vector>
#include <algorithm> 
using namespace std;

/* 

F(n) = P(n) + min(P(n-1) + P(n-2));

*/

int main() {
    int n = 8, k = 2;
    vector<int> prices = {3, 2, 4, 6, 1, 1, 5, 3};
    vector<int> tab(n + 1 , 0);
    vector<int> dp(n + 1 , 0);

    dp[0] = 0;
    dp[1] = prices[0];

    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + prices[i-1];
        if (dp[i - 1] < dp[i - 2]) {
            tab[i] = i-1;
        } else {
            tab[i] = i-2;
        }
    }
    vector<int> ans;
    for (int i = n; i > 0;i = tab[i]) {
        ans.push_back(i);
    }
    ans.push_back(0);

    reverse(ans.begin(), ans.end());

    for (auto i : ans) {
        cout << i << ", ";
    }
    return 0;
}