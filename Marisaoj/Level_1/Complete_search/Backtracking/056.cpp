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
 
struct Query {
    int i, j, k;
};

const int N = 10;
int n, m, q, a[N], used[N];
Query query[N];
ll ans = 0;

bool check() {
    for (int t = 0; t < q; t++) {
        auto [i, j, k] = query[t];
        if (a[i] + a[j] != k) return false;
    }
    return true;
}

void gen_array(int i) {
    if (i == n+1) {
        if (check()) ans++;
        return;
    }
    for (int val = 1; val <= m; val++) {
        a[i] = val;
        gen_array(i+1);
    }
}

void solve(){
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        cin >> query[i].i >> query[i].j >> query[i].k;
    }
    gen_array(1);
    cout << ans;
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