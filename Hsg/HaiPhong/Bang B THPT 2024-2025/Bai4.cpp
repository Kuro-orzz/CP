#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int n, q; cin >> n >> q;
    vector<vector<ll> > a(n+1, vector<ll>(n+1, 1));
    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= n; j++)
            a[i][j] = (a[i-1][j] + a[i][j-1]) % MOD;
    while(q--){
        int u, v; cin >> u >> v;
        cout << a[n-u+1][n-v+1] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    freopen("bai4.inp", "r", stdin);
    freopen("bai4.out", "w", stdout);
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
