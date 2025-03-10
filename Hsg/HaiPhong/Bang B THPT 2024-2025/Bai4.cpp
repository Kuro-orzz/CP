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
    vector<vi> a(n+1, vi(n+1, 1));
    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= n; j++)
            a[i][j] = (a[i-1][j] + a[i][j-1]) % MOD;
    while(q--){
        int u, v; cin >> u >> v;
        cout << a[5-u+1][5-v+1] << '\n';
    }
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
