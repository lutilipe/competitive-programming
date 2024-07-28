#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int m = low + (high - low) / 2;
    int pivot = nums[m];
    while (high >= low) {
        while (nums[low] < pivot) low++;
        while (nums[high] > pivot) high--;
        if (high >= low) {
            swap(nums[high], nums[low]);
            low++;
            high--;
        }
    }
    return low;
}

void quickSort(vector<int>& nums, int low, int high) {
    if (high > low) {
        int lastPivotIdx = partition(nums, low, high);
        
        quickSort(nums, low, lastPivotIdx - 1);
        quickSort(nums, lastPivotIdx, high);
    }
}

int main() {
    vector<int> arr = {0, 4, 1, 5, 3, 2, 7};
    quickSort(arr, 0, arr.size() - 1);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
