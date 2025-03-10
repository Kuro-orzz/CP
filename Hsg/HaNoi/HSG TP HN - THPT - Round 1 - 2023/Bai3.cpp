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
    int n, m, d, k; cin >> n >> m >> d >> k;
    vector<vector<char>> a(n+1, vector<char>(m+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int t = (a[i][j]=='M'?1:0);
            pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+t;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 'P'){
                pii v1 = {max(i-d, 1), max(j-d, 1)};
                pii v2 = {max(i-d, 1), min(j+d, m)};
                pii v3 = {min(i+d, n), max(j-d, 1)};
                pii v4 = {min(i+d, n), min(j+d, m)};
                int cnt = pre[v4.fi][v4.se]-pre[v3.fi][v3.se-1]-pre[v2.fi-1][v2.se]+pre[v1.fi-1][v1.se-1];
                if(cnt >= k) ans++;
            }
        }
    cout << ans;
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
