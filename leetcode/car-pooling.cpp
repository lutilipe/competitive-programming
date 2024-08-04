#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    // Map maintain keys in a ascending order (log n)
    map<int, int> timestamps;
    for (auto& trip : trips) {
        timestamps[trip[1]]+=trip[0];
        timestamps[trip[2]]-=trip[0];
    }

    int currentPassangers = 0;

    for (auto& [timestamp, tripPassangers] : timestamps) {
        currentPassangers += tripPassangers;
        if (currentPassangers > capacity) return false;
    }

    return true;
}

int main() {
    vector<vector<int>> in = {{3,3,7},{2,1,5}};
    cout << carPooling(in, 4) << endl;
    return 0;
}