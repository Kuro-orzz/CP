// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

vector<vector<char>> grid;
vector<vector<int>> vis;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, cnt;

bool isValid(pii u){
    return u.fi >= 0 && u.fi < 2 && u.se >= 0 && u.se < n;
}

void dfs(pii u){
    vis[u.fi][u.se] = cnt;
    for(int i = 0; i < 4; i++){
        pii v = {u.fi+dx[i], u.se+dy[i]};
        if(isValid(v) && !vis[v.fi][v.se] && grid[v.fi][v.se] == '.')
            dfs(v);
    }
}

void solve(){
    cin >> n;
    cnt = 0;
    grid.clear();
    grid.resize(2, vector<char>(n));
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    vis.clear();
    vis.resize(2, vector<int>(n, 0));
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                cnt++;
                dfs({i, j});
            }
        }
    int ans = 0;
    if(cnt == 1){
        for(int i = 0; i < 2; i++)
            for(int j = 1; j < n-1; j++){
                if(grid[i^1][j-1] == 'x' && grid[i^1][j+1] == 'x' && grid[i][j] == '.' && grid[i][j-1] == '.' && grid[i][j+1] == '.' && grid[i^1][j] == '.')
                    ans++;
            }
    }
    else if(cnt == 2){
        for(int i = 0; i < 2; i++)
            for(int j = 1; j < n-1; j++){
                if(grid[i][j] == 'x') continue;
                if(grid[i^1][j-1] == 'x' && grid[i^1][j+1] == 'x' && grid[i][j] == '.' && grid[i][j-1] == '.' && grid[i][j+1] == '.' && grid[i^1][j] == '.')
                    continue;
                if(i == 0){
                    if(grid[i][j-1] == '.' && grid[i^1][j-1] == 'x' && (grid[i][j+1] == '.' || grid[i^1][j] == '.'))
                        ans++;
                    else if(grid[i][j-1] == '.' && grid[i^1][j] == 'x' && grid[i][j+1] == '.')
                        ans++;
                    else if(grid[i][j+1] == '.' && grid[i^1][j+1] == 'x' && (grid[i][j-1] == '.' || grid[i^1][j] == '.'))
                        ans++; 
                }
                else{
                    if(grid[i][j+1] == '.' && grid[i^1][j+1] == 'x' && (grid[i][j-1] == '.' || grid[i^1][j] == '.'))
                        ans++;
                    else if(grid[i][j-1] == '.' && grid[i^1][j] == 'x' && grid[i][j+1] == '.')
                        ans++;
                    else if(grid[i][j-1] == '.' && grid[i^1][j-1] == 'x' && (grid[i][j+1] == '.' || grid[i^1][j] == '.'))
                        ans++; 
                }
            }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif    
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}