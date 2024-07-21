#include <iostream>

#include <vector>
#include <algorithm> 
using namespace std;

/* 

There is a fance with n posts. We can paint each post with two different colors, but
three or more consecutive posts can't be painted using the same color
 
1) Last two post are painted with different colors
|^|-|^|-|^|-|^|
         b   g(m)

F(m-1, 1-n) -> we still can paint m-1 posts with 1-n colors (if n = 1, than 0, and so on)

or (+)

2)
|^|-|^|-|^|-|^|
         g   g

F(m-2, 1-n)

green = 1
blue = 0

m = number of posts
n = color of the post

F(m,n) = F(m-1, 1-n) + F(m-2, 1-n)

*/

int res(int i) {
    vector<vector<int>> dp(i+1, vector<int>(2, 0));

    // Base cases for green = 1 and blue = 0
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[2][0] = 2;
    dp[2][1] = 2;

    for (int m = 3; m <= i; m++) {
        for (int n = 0; n < 2; n++) {
            dp[m][n] = dp[m-1][1-n]+dp[m-2][1-n];
        }
    }

    return dp[i][0] + dp[i][1];
}

int main() {
    cout << res(4) << endl;
    return 0;
}