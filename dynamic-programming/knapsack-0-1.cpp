#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int knapsack(int capacity, vector<int>& W, vector<int>& V) {
    int numItems = V.size();
    vector<vector<int>> DP(numItems + 1, vector<int>(capacity+1, 0));
    for (int i = 1; i <= numItems; i++) {
        int currItemWeight = W[i-1];
        int currItemValue = V[i-1];
        for (int j = 1; j <= capacity; j++) {
            DP[i][j] = DP[i-1][j];
            if (currItemWeight <= j) {
                int sum = DP[i-1][j-currItemWeight] + currItemValue;
                DP[i][j] = max(sum, DP[i-1][j]);
            }
        } 
    }

    return DP[numItems][capacity];
}


int main() {
    vector<int> value = {2,2,4,5,3};
    vector<int> weight = {3,1,3,4,2};
    int capacity = 7;

    vector<int> itemsSelected;

    cout << knapsack(capacity, weight, value) << endl;

    return 0;
}
