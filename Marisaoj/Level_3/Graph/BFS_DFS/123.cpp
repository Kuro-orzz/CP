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
vector<int> ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt = 0;

bool isValid(pii u, int n, int m){
    return u.fi >= 1 && u.fi <= n && u.se >= 1 && u.se <= m;
}

void dfs(pii u, int n, int m){
    if(a[u.fi][u.se] == 'x')
        cnt++;
    vis[u.fi][u.se] = 1;
    for(int i = 0; i < 4; i++){
        pii v = {u.fi+dx[i], u.se+dy[i]};
        if(isValid(v, n, m)  && !vis[v.fi][v.se] && a[v.fi][v.se] != '#')
            dfs(v, n, m);
    }
}

void solve(){
    int n, m; cin >> n >> m;
    a.resize(n+1, vector<char>(m+1));
    vis.resize(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(!vis[i][j] && a[i][j] != '#'){
                cnt = 0;
                dfs({i, j}, n, m);
                if(cnt) ans.push_back(cnt);
            }
    sort(all(ans));
    for(int x : ans)
        cout << x << ' ';
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