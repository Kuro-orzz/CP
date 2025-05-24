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
    int n, m, q; cin >> n >> m >> q;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    ll pre[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++)
            if(!i || !j) pre[i][j] = 0;
            else
                pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i-1][j-1];
    }
    while(q--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << pre[c][d]-pre[c][b-1]-pre[a-1][d]+pre[a-1][b-1] << '\n';
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