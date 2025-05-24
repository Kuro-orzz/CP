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

const int N = 1e5+6;
int n, a[N], b[N];
ll dp[N][2][3];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    dp[1][0][1] = a[1];
    dp[1][1][1] = b[1];
    for (int i = 2; i <= n; i++) {
        dp[i][0][1] = max(dp[i-1][1][1], dp[i-1][1][2]) + a[i];
        dp[i][0][2] = dp[i-1][0][1] + a[i];
        dp[i][1][1] = max(dp[i-1][0][1], dp[i-1][0][2]) + b[i];
        dp[i][1][2] = dp[i-1][1][1] + b[i];
    }
    cout << max({dp[n][0][1], dp[n][0][2], dp[n][1][1], dp[n][1][2]});
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
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