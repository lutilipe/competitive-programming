#include <iostream>
using namespace std;

// ################  Conceitos  ###################

string isOddOrEven(int n) {
    if (n & 1) {
        return "Odd";
    }
    return "Even";
}

int getIthBit(int n, int i) {
    int mask = 1 << i;
    return (n & mask) > 0 ? 1 : 0;
}

void setIthBit(int &n, int i) {
    int mask = 1 << i;
    n = n|mask;
}

void clearIthBit(int &n, int i) {
    int mask = ~(1 << i);
    n = n & mask;
}

void updatedIthBit(int &n, int i, int v) {
    clearIthBit(n, i);
    int mask = v << i;
    n = n|mask;
}

void clearLastIthBits(int &n, int i) {
    int mask = -1 << i;
    n = n & mask;
}

void clearBitsInRange(int &n, int i, int j) {
    /* 
        n = 15 | i = 2 | j = 1
        00001111 // 15
        11111000 // a
        00000001 // b
        11111001 // mask
        00001011 // Res = 9
     */
    int a = -1 << i + 1;
    int b = (1 << j) - 1;
    int mask = a|b;
    n = n & mask;
}

// ###################################

int main() {
    int t = 0;

    // #1
    cout << ~t << endl; // -1

    // #2
    cout << "3: " << isOddOrEven(3) << " 4: " << isOddOrEven(4) << endl;

    // #3
    cout << "5[2]: " << getIthBit(5, 2) << endl;

    // #4
    int n = 3;
    clearIthBit(n, 0);
    cout << "N(3) => 2: " << n << endl;

    // #5
    setIthBit(n, 0);
    cout << "N(2) => 3: " << n << endl;

    // #6
    updatedIthBit(n, 2, 1);
    cout << "N(3) => 7: " << n << endl;

    // #7
    int m = 15;
    clearLastIthBits(m, 3);
    cout << "N(15) => 8: " << m << endl;

    // #7
    int o = 15;
    clearBitsInRange(o, 2, 1);
    cout << "N(15) => 9: " << o << endl;

    return 0;
}