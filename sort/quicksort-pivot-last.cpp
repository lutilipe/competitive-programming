#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int low, int highest) {
    int pivot = nums[highest];
    int i = low-1;
    for (int j = low; j < highest; j++) {
        if (pivot >= nums[j]) {
            i++;
            if (i != j) {
                swap(nums[i], nums[j]);
            }
        }
    }
    swap(nums[i+1], nums[highest]);
    return i+1;
}
    
void quickSort(vector<int>& nums, int low, int highest) {
    if (highest > low) {
        int lastPivotIdx = partition(nums, low, highest);
        
        quickSort(nums, low, lastPivotIdx-1);
        quickSort(nums, lastPivotIdx+1, highest);
    }
}

int main() {
    vector<int> arr = {0, 4, 1, 5, 3, 2, 7};
    quickSort(arr, 0, arr.size()-1);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}