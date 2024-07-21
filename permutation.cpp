#include <iostream>

#include <vector>
#include <algorithm> 
using namespace std;


void permute(string a, int l, int r) { 
    if (l == r) {
        cout << a << endl;
        return;
    }

    for (int i = l; i <= r; i++) { 
        swap(a[l], a[i]); 
        permute(a, l + 1, r); 
        swap(a[l], a[i]); 
    } 
} 

int main() {
    string str = "ABC"; 
    permute(str, 0, str.size()-1); 
    return 0; 
}