#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int N = 1e5 + 6;
int n, a[N];
ll k, pref[N], sum[N];

bool check(int avg) {
    pref[0] = sum[0] = 0;
    ll mn = 1e18;
    int l = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i-1] - avg;
        sum[i] = sum[i-1] + a[i-1];
        while (l < i && sum[i] - sum[l] >= k) {
            mn = min(mn, pref[l++]);
            if (pref[i] - mn >= 0) return true;
        }
    }
    return false;
}

ll binSearch() {
    int l = 0, r = 1e9;
    ll ans = -1e18;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = binSearch();
    if (ans == -1e18) cout << "NO";
    else cout << ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("bai2.inp", "r", stdin);
    freopen("bai2.out", "w", stdout);
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
