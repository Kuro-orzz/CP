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

vector<vector<char>> a;
vector<vi> vis;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool isValid(int n, pii u){
    return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < n;
}

bool check(int n, pii u){
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        pii v = {u.fi+dx[i], u.se+dy[i]};
        if(isValid(n, v) && a[v.fi][v.se] == '.' && !vis[v.fi][v.se])
            cnt++;
    }
    return cnt == 4;
}

void solve(){
    int n; cin >> n;
    a.resize(n, vector<char>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    vis.resize(n, vi(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!vis[i][j] && a[i][j] == '.' && check(n, {i, j})){
                vis[i][j] = 1;
                for(int k = 0; k < 4; k++){
                    pii v = {i+dx[k], j+dy[k]};
                    vis[v.fi][v.se] = 1;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] == '.' && !vis[i][j]){
                cout << "NO";
                return;
            }
    cout << "YES";
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