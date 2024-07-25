#include <iostream>

#include <vector>
#include <algorithm> 
using namespace std;


void permute(string a, int l) { 
    if (l == a.size()-1) {
        cout << a << endl;
        return;
    }

    for (int i = l; i <= a.size()-1; i++) { 
        swap(a[l], a[i]); 
        permute(a, l + 1); 
        swap(a[l], a[i]); 
    } 
} 

int main() {
    string str = "ABC"; 
    permute(str, 0); 
    return 0; 
}