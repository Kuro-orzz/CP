#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e5+6;
int n, t[maxn], r[maxn], dp[maxn][2];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 2; i <= n; i++)
        cin >> r[i];
    dp[1][0] = t[1];
    dp[1][1] = 1e9;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + t[i];
        dp[i][1] = min(dp[i-2][0], dp[i-2][1]) + r[i];
    }
    cout << min(dp[n][0], dp[n][1]);
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