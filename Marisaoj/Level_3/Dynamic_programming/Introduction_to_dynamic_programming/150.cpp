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
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(501, vector<int>(501, INT_MAX));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == j) {
                dp[i][j] = 0;
                continue;
            }
            for(int k = 1; k < i; k++)
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            for(int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1); 
        }
    }
    cout << dp[n][m];
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