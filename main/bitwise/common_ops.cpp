#include <bits/stdc++.h>

using namespace std;

bool getBit(int n, int i) {
    int mask = 1 << i;
    return n & 1;
}

int setBitTo1(int n, int i) {
    int mask = 1 << i;
    return n | mask;
}

int clearBit(int n, int i) {
    int mask = ~(1 << i);
    return n & mask;
}

int main() {
    cout << getBit(1, 0) << endl;
    cout << setBitTo1(1, 2) << endl;
    cout << clearBit(3, 1) << endl;
    return 0;
}