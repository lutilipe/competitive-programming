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

int updateIthBit(int n, int i, bool v) {
    n = clearBit(n, i);
    int mask = v << i;
    return n | mask;
}

int clearLastIthBits(int n, int i) {
    int mask = ~0 << i;
    return n & mask;
}

int clearBitsInRange(int n, int i, int j) {
    int a = ~0 << (j+1);
    int b = (1 << i) - 1;
    int mask = a|b;
    return n & mask;
}

int main() {
    cout << getBit(1, 0) << endl;
    cout << setBitTo1(1, 2) << endl;
    cout << clearBit(3, 1) << endl;
    return 0;
}