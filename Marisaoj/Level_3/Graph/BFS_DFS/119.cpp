#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<vector<char>> a;
vector<vector<int>> vis, d;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(pii u, int n, int m){
    queue<pii> q;
    q.push(u);
    vis[u.fi][u.se] = 1;
    d[u.fi][u.se] = 0;
    auto isValid = [&](pii u, int n, int m){
        return u.fi >= 1 && u.fi <= n && u.se >= 1 && u.se <= m;
    };
    while(!q.empty()){
        pii v = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            pii p = {v.fi+dx[i], v.se+dy[i]};
            if(isValid(p, n, m)  && !vis[p.fi][p.se] && a[p.fi][p.se] == '0'){
                d[p.fi][p.se] = d[v.fi][v.se]+1;
                vis[p.fi][p.se] = 1;
                q.push(p);
            }
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    a.resize(n+1, vector<char>(m+1));
    vis.resize(n+1, vector<int>(m+1, 0));
    d.resize(n+1, vector<int>(m+1, -1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    bfs({1, 1}, n, m);
    cout << d[n][m];
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