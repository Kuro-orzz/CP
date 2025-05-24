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
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int sum = 0;
    x--; y--;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(x-cnt >= 0 && y-cnt >= 0)
            sum += a[x-cnt][y-cnt];
        cnt++;
    }
    cnt = 0;
    for(int i = 0; i < n; i++){
        if(x-cnt >= 0 && y+cnt < m)
            sum += a[x-cnt][y+cnt];
        cnt++;
    }
    cnt = 0;
    for(int i = 0; i < n; i++){
        if(x+cnt < n && y-cnt >= 0)
            sum += a[x+cnt][y-cnt];
        cnt++;
    }
    cnt = 0;
    for(int i = 0; i < n; i++){
        if(x+cnt < n && y+cnt < m)
            sum += a[x+cnt][y+cnt];
        cnt++;
    }
    cout << sum-3*a[x][y];
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