#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 41;
int n, a[maxn];
ll ans = 0;
vector<ll> L, R;

void MITM(int i, ll sum, int end) {
    if (i >= end) R.push_back(sum);
    else {
        MITM(i+1, sum, end);
        MITM(i+1, sum + a[i], end);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    MITM(0, 0, n/2);
    L = R;
    R.clear();
    MITM(n/2, 0, n);
    for (ll &x : L) x %= (int)1e9;
    for (ll &x : R) x %= (int)1e9;
    sort(all(R));
    for (int i = 0; i < L.size(); i++) {
        auto it = lower_bound(all(R), (int)1e9-L[i])-R.begin();
        if (it == R.size()) 
            ans = max(ans, L[i] + R[it-1]);
        else if (it == 0)
            ans = max(ans, (L[i] + R[it]) % (int)1e9);
        else
            ans = max({ans, (L[i]+R[it]) % (int)1e9, (L[i]+R[it-1]) % (int)1e9});
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