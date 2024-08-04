#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

/* 

A  0.9  B    C

0.5

D 0.45  E       F

0.25

G       H       I

*/

int main() {
    vector<vector<int>> vec = {{0,0}, {0,1}, {1,1}};
    double horizontal = .9;
    double vertical = 1.0;

    double chanceOfSuccess = 1;

    for (int i = 1; i < vec.size(); i++) {
        int divisor = pow(2, vec[i][1]);
    }

    cout << 1 - chanceOfSuccess << endl;
    
    return 0;
}