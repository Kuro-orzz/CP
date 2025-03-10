#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<vector<int>> a;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int bfs(pii s, pii t, int n, int m, vector<vector<pii>> &val){
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pii, int>> q;
    vector<int> vis_same(val.size(), 0);
    q.push({s, 0});
    vis[s.fi][s.se] = 1;
    auto isValid = [&](pii u){
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    };
    while(!q.empty()){
        pair<pii, int> u = q.front(); q.pop();
        if(u.fi == t) return u.se;
        for(int i = 0; i < 4; i++){
            pii v = {u.fi.fi+dx[i], u.fi.se+dy[i]};
            if(isValid(v) && a[v.fi][v.se] && !vis[v.fi][v.se]){
                vis[v.fi][v.se] = 1;
                q.push({v, u.se+1});
            }
        }
        if(vis_same[a[u.fi.fi][u.fi.se]]) continue;
        vis_same[a[u.fi.fi][u.fi.se]] = 1;
        for(pii x : val[a[u.fi.fi][u.fi.se]]){
            if(!vis[x.fi][x.se]){
                vis[x.fi][x.se] = 1;
                q.push({x, u.se+1});
            }
        }
    }
    return -1;
}

void solve(){
    int n, m; cin >> n >> m;
    pii s, t;
    cin >> s.fi >> s.se >> t.fi >> t.se;
    s.fi--; s.se--; t.fi--; t.se--;
    a.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<pii> v;
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            v.push_back({a[i][j], cnt++});
    sort(all(v));
    if(v[0].fi == 0) cnt = 0;
    else cnt = 1;
    for(int i = 0; i < v.size(); i++){
        if(i+1 < v.size() && v[i].fi < v[i+1].fi)
            a[v[i].se/m][v[i].se%m] = cnt++;
        else
            a[v[i].se/m][v[i].se%m] = cnt;
    }
    vector<vector<pii>> val(cnt+1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            val[a[i][j]].push_back({i, j});
        }
    cout << bfs(s, t, n, m, val);
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    freopen("BAI4.INP", "r", stdin);
    freopen("BAI4.OUT", "w", stdout);
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
