#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

pair<int, int> splitTime(string& time) {
    char delimiter = ':';
    auto it = time.find(delimiter);

    return make_pair(
        stoi(time.substr(0, it)),
        stoi(time.substr(it+1))
    );
}

bool compareTime(string& t1, string& t2) {
    auto [hour1, min1] = splitTime(t1);
    auto [hour2, min2] = splitTime(t2);
    if (hour1 != hour2) return hour1 > hour2;
    return min1 > min1;
}

int main() {
    string time1 = "21:00";
    string time2 = "12:01";

    cout << compareTime(time1, time2) << endl;
    
    return 0;
}