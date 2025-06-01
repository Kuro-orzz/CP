#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())
#define inf (ll)1e18

#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

class BinLift {
public:
    int n;
    vector<vector<int>> up;

    BinLift() {}
    BinLift(int n): n(n), up(n+1, vector<int>(32)) {}

    // up[n][32]: from i up to 2^j
    void preprocess(vector<int> &a) {
        for (int i = 1; i <= n; i++) {
            up[i][0] = a[i];
        }
        for (int j = 1; j < 32; j++) {
            for (int i = 1; i <= n; i++) {
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }

    int ancestor_k(int u, int k) {
        for(int j = 0; (1 << j) <= k; j++) {
            if(k >> j & 1)
                u = up[u][j];
        }
        return u;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    BinLift binlift(n);
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    binlift.preprocess(a);
    while (q--) {
        int u, x; cin >> u >> x;
        cout << binlift.ancestor_k(u, x) << '\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}