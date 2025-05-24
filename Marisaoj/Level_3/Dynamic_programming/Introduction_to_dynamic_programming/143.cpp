#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e3+6;
int n, a[maxn], dp[maxn];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j]+1);
    }
    cout << *max_element(dp, dp+n);
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