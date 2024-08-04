#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int minimumPartition(int i, int currSum, int totalSum, vector<int>& nums, vector<vector<int>>& dp) {
    if (i == 0) {
        return abs((totalSum - currSum) - currSum);
    } 

    if (dp[i][currSum] != -1) return dp[i][currSum];

    dp[i][currSum] =  min(
        minimumPartition(i - 1, currSum, totalSum, nums, dp),
        minimumPartition(i - 1, currSum + nums[i-1], totalSum, nums, dp)
    );

    return dp[i][currSum];
}


int main() {
    vector<int> nums = {1, 6, 11, 5};

    int n = nums.size();

    int sumTotal = 0;
    for (int i = 0; i < n; i++)
        sumTotal += nums[i];

    vector<vector<int>> dp(n + 1,
        vector<int>(sumTotal + 1, -1));

    cout << minimumPartition(n, 0, sumTotal, nums, dp) << endl;

    return 0;
}
