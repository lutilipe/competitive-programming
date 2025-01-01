#include <bits/stdc++.h>

using namespace std;

bool isOdd(int i) {
    return i & 1;
}

int main() {
    cout << isOdd(2) << endl; // 0
    cout << isOdd(3) << endl; // 1
    return 0;
}