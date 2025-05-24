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

const int N = 1e3 + 6;
int n, a[N], b[N];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    cout << dp[n][n];
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