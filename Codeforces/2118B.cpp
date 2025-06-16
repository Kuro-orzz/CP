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

struct Op {
    int i, l, r;
    Op() {}
    Op(int _i, int _l, int _r): i(_i), l(_l), r(_r) {}
};

void solve() {
    int n; cin >> n;
    vector<Op> ans;
    for (int i = 1; i <= n; i++) {
        ans.emplace_back(i, 1, i);
        ans.emplace_back(i, min(i+1, n), n);
    }
    cout << ans.size() << '\n';
    for (auto it : ans) {
        cout << it.i << " " << it.l << " " << it.r << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}