#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N = 1e4 + 6;
ll H[N];

void preprocess() {
    for (int i = 0; i < N; i++) {
        H[i] = rng() % (ll)1e14;
    }
}

bool check(vector<ll> &a, vector<ll> &b) {
    sort(all(a));
    sort(all(b));
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void solve() {
    preprocess();
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<ll> a_row(n), a_col(m), b_row(n), b_col(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                a_row[i] += H[x];
                a_col[j] += H[x];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                b_row[i] += H[x];
                b_col[j] += H[x];
            }
        }
        int tmp1 = check(a_row, b_row);
        int tmp2 = check(a_col, b_col);
        if (tmp1 && tmp2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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
