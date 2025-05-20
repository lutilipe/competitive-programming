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
    double vertical = 1;

    double chanceOfSuccess = 1;

    for (int i = 1; i < vec.size(); i++) {
        vector<int> l = vec[i-1];
        if (vec[i][0] != l[0]) {
            chanceOfSuccess*=(vertical/pow(2, max(vec[i][0], l[0])));
        } else if (vec[i][1] != l[1]) {
            chanceOfSuccess*=(horizontal/pow(2, max(vec[i][0], l[0])));
        }
    }

    cout << 1 - chanceOfSuccess << endl;
    
    return 0;
}