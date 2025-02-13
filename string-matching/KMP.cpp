#include <bits/stdc++.h>

using namespace std;

vector<int> LPS(string& pattern) {
    int n = pattern.size();
    vector<int> lps(pattern.size());
    int j = 0;
    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[j]) {
            j++;
            lps[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = lps[j-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool KMP(string& text, string& pattern) {
    vector<int> lps = LPS(pattern);
    int i = 0;
    int j = 0;
    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == pattern.size()) {
            return true;
        } else {
            if (i < text.size() && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
        }
    }
    return false;
}

int main() {
    string a = "superhero";
    string b = "hero";
    cout << KMP(a, b) << endl;
    return 0;
}