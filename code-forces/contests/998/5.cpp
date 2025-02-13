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

class DSU {

    vi parent;
    vi rank;

    public:
    DSU(int n) {
        parent.resize(n +1);
        rank.resize(n+1);

        for (int i=1;i<=n;i++){
            parent[i] = i;
        }
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py])
            swap(px, py);
        
        parent[py] = px;

        if (rank[px] == rank[py])
            rank[px]++;
    }


    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n,m1,m2;
    cin >> n>>m1>>m2;
    DSU* fDSU = new DSU(n);
    DSU* gDSU = new DSU(n);

    vpi edges_F(m1);
    vpi edges_G(m2);

    for (int i=0;i<m1;i++){
        int a,b;
        cin >> a >> b;
        edges_F[i] = make_pair(a,b);
    }

    for (int i=0;i<m2;i++){
        int a,b;
        cin >> a >> b;
        gDSU->unite(a,b);
        edges_G[i] = make_pair(a,b);
    }
    
    int c =0;
    
    for (auto& edge : edges_F) {
        int u = edge.F;
        int v = edge.S;

        if (!gDSU->same(u,v)) {
            c++;
        } else {
            fDSU->unite(u,v);
        }
    }

    for (auto& edge : edges_G) {
        int u = edge.F;
        int v = edge.S;

        if (!fDSU->same(u,v)) {
            c++;
            fDSU->unite(u,v);
        }
    }

    cout << c << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt",  "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}
