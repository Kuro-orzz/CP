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
    int n, t; cin >> n >> t;
    vector<vector<ll>> row(n+4, vector<ll>(n+4, 0)), col(n+4, vector<ll>(n+4, 0));
    while(t--){
        int k, rc, x, y; cin >> k >> rc >> x >> y;
        int sz = y-x+1;
        int t = (sz%2==0 ? 2 : 1);
        if(k == 1){
            row[rc][x]++;
            row[rc][((x+y)>>1)+1]--;
            row[rc][((x+y)>>1)+t]--;
            row[rc][y+2]++;
        }
        else{
            col[rc][x]++;
            col[rc][((x+y)>>1)+1]--;
            col[rc][((x+y)>>1)+t]--;
            col[rc][y+2]++;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            row[i][j] += row[i][j-1];
            col[i][j] += col[i][j-1];
        }
    for(int i = 1; i <= n; i++){
        ll sum1 = 0, sum2 = 0;
        for(int j = 1; j <= n; j++){
            sum1 += row[i][j];
            row[i][j] = sum1;
            sum2 += col[i][j];
            col[i][j] = sum2;
        }
    }
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        cout << row[u][v]+col[v][u] << '\n';
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
