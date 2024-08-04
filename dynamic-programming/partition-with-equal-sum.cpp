#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

bool partitionWithEqualSum(int i, int sum, vector<int>& nums) {
    if (sum == 0) {
        return true;
    }

    if (i == 0 && sum != 0) {
        return false;
    }

    if (nums[i-1] > sum) {
        return partitionWithEqualSum(i-1, sum, nums);
    }

    return partitionWithEqualSum(i-1, sum - nums[i-1], nums) || partitionWithEqualSum(i-1, sum, nums);
}


int main() {
    vector<int> nums = { 3, 1, 5, 9, 12 };

    int n = nums.size();

    int sumTotal = 0;
    for (int i = 0; i < n; i++)
        sumTotal += nums[i];

    cout << partitionWithEqualSum(n, sumTotal/2, nums) << endl;

    return 0;
}
