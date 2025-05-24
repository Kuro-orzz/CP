#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pll pair<ll, ll>
#define fi first
#define se second

const int maxn = 41;
int n, S;
ll ans = 0;
vector<pll> a, L, R;

void MITM(int i, pll sum, int end) {
    if (sum.fi > S) return;
    if (i >= end) R.push_back(sum);
    else {
        MITM(i+1, sum, end);
        pll x = {sum.fi+a[i].fi, sum.se+a[i].se};
        MITM(i+1, x, end);
    }
}

int upperBound(int l, int r, ll x) {
    int ans = r+1;
    while (l < r) {
        int mid = l+(r-l)/2;
        if (R[mid].fi <= x) l = mid+1;
        else {
            ans = mid;
            r = mid-1;
        }
    }
    return ans;
}

void solve() {
    cin >> n >> S;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    MITM(0, {0, 0}, n/2);
    L = R;
    R.clear();
    MITM(n/2, {0, 0}, n);
    sort(all(R));
    for (int i = 1; i < R.size(); i++) {
        R[i].second = max(R[i].second, R[i-1].second);
    }
    for (int i = 0; i < L.size(); i++) {
        int it = upperBound(0, R.size()-1, S-L[i].fi);
        if (it == 0) {
            ans = max(ans, L[i].se);
        }
        else {
            ans = max(ans, L[i].se + R[it-1].se);
        }
    }
    cout << ans;
}
 
int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
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