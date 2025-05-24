#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<int> vis;

int bfs(int n, int m){
    queue<pii> q;
    q.push({n, 0});
    vis[n] = 1;
    while(!q.empty()){
        pii v = q.front(); q.pop();
        if(v.fi == m) return v.se;
        if(v.fi < m && !vis[v.fi*2]){
            q.push({v.fi*2, v.se+1});
            vis[v.fi*2] = 1;
        }
        if(v.fi-1 >= 0 && !vis[v.fi-1]){
            q.push({v.fi-1, v.se+1});
            vis[v.fi-1] = 1;
        }
    }
    return -1;
}

void solve(){
    int n, m; cin >> n >> m;
    vis.resize(2e5+6, 0);
    cout << bfs(n, m);
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