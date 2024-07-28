#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSort(vector<int>& nums, int low, int high) {
    if (low > high) {
        return {};
    } 
    if (low == high) {
        return {nums[low]};
    }

    int m = low + (high - low) / 2;
    vector<int> lv = mergeSort(nums, low, m);
    vector<int> rv = mergeSort(nums, m + 1, high);

    vector<int> res;
    int l = 0;
    int r = 0;

    while (l < lv.size() && r < rv.size()) {
        if (lv[l] < rv[r]) {
            res.push_back(lv[l]);
            l++;
        } else {
            res.push_back(rv[r]);
            r++;
        }
    }

    while (l < lv.size()) {
        res.push_back(lv[l]);
        l++;
    }
    
    while (r < rv.size()) {
        res.push_back(rv[r]);
        r++;
    }

    return res;
}

int main() {
    vector<int> arr = {5,2,3,1};
    arr = mergeSort(arr, 0, arr.size() - 1);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
