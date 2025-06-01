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

template <typename T>
struct RMQ {
    int n;
    vector<vector<T>> mn;
    vector<int> a;

    RMQ() {}
    RMQ(int _n, vector<int> &_a): n(_n) {
        mn = vector<vector<T>>(20, vector<T>(_n+1));
        this->a = _a;
    }

    void preprocess() {
        for (int i = 1; i <= n; i++) {
            mn[0][i] = i;
        }
        for (int i = 1; i < 20; i++) {
            for (int j = 1; j + (1 << i) - 1 <= n; j++) {
                int idx1 = mn[i-1][j], idx2 = mn[i-1][j + (1 << (i-1))];
                if (a[idx1] <= a[idx2]) {
                    mn[i][j] = idx1;
                } else {
                    mn[i][j] = idx2;
                }
            }
        }
    }

    T queryMin(int l, int r) {
        int k = __lg(r-l+1);
        int idx1 = mn[k][l], idx2 = mn[k][r - (1 << k) + 1];
        if (a[idx1] <= a[idx2]) {
            return idx1;
        } else {
            return idx2;
        }
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    RMQ<int> rmq(n, a);
    rmq.preprocess();
    while (q--) {
        int l, r; cin >> l >> r;
        cout << rmq.queryMin(l, r) << '\n';
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