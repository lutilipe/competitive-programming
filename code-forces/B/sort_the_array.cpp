#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define vii            vector <vector <int>>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define zr             (int) 0
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define ANS(ans)       cout << ans << endl
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define REPL(i,a,b)    for (int i = a; i < b; i++)
#define REPR(i,a,b)    for (int i = a-1; i >= b; i--)
#define PI             3.141592653589793238
#define INF            LONG_LONG_MAX
#define MOD            1e9+7
#define IMAX           LONG_LONG_MAX
#define IMIN           LONG_LONG_MIN

struct PqCompare {
    bool operator()(pair<int, int>& a1, pair<int, int>& a2) {
        if (a2.first != a1.first) {
            return a1.first > a2.first;
        }
        return a1.second > a2.second;
    }
};

inline int power(int a, int b) {
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

int isIncreasing(vi& v) {
    int idx = -1;
    for (int i=0;i<v.size()-1;i++) {
        if (v[i] > v[i+1]) {
            idx = i;
            break;
        }
    }
    return idx;
}

void reverse(vi& v, int s, int e) {
    for (int i=0;i<=(e-s)/2;i++) {
        int tmp = v[i+s];
        v[i+s] = v[e-i];
        v[e-i] = tmp;
    }
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int i=0;i<n;i++){
        cin >> v[i];
    }

    int didx = isIncreasing(v);

    if (didx == -1) {
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }
    
    int i = didx;
    for (i = didx; i < v.size() -1; i++) {
        if (v[i] < v[i+1]) {
            break;
        }
    }

    reverse(v, didx, i);
    if (isIncreasing(v) == -1) {
        cout << "yes" << endl;
        cout << didx + 1 << " " << i + 1 << endl;
    } else {
        cout << "no" << endl;
    }
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt",  "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}