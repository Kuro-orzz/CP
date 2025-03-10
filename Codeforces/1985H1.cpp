#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)
#define MOD (int)(1e9+7)
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct dsu_2D{
    vector<vector<pii>> par;
    vector<vector<int>> sz;
    dsu_2D(int n, int m): par(n, vector<pii>(m)), sz(n, vector<int>(m, 1)){
        for(int i = 0; i < par.size(); i++)
            for(int j = 0; j < par[i].size(); j++)
                par[i][j] = {i, j};
    }
    pii find(pii v){
        if(v == par[v.fi][v.se])
            return v;
        return par[v.fi][v.se] = find(par[v.fi][v.se]);
    }
    void Union(pii a, pii b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(sz[a.fi][a.se] < sz[b.fi][b.se]) swap(a, b);
            par[b.fi][b.se] = a;
            sz[a.fi][a.se] += sz[b.fi][b.se];
        }
    }
    int Max_opponent(){
        int res = 0;
        for(int i = 0; i < par.size(); i++)
            for(int j = 0; j < par[i].size(); j++){
                res = max(res, sz[i][j]);
            }
        return res;
    }
    int Try_Row(int k, vector<vector<char>> &a){
        auto isValid = [&](int n, int m, pii u)->bool {
            return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
        };
        int n = a.size();
        int m = a[0].size();
        int dx[2] = {-1, 1};
        int dy[2] = {0, 0};
        int res = 0;
        set<pii> s;
        for(int i = 0; i < par[k].size(); i++){
            if(a[k][i] == '.') res++;
            if(a[k][i] == '#'){
                pii x = find({k, i});
                if(s.find(x) == s.end()){
                    res += sz[x.fi][x.se];
                    s.insert({x.fi, x.se});
                }
            } 
            for(int j = 0; j < 2; j++){
                pii u = {k+dx[j], i+dy[j]};
                if(isValid(n, m, u) && a[u.fi][u.se] == '#'){
                    pii v = find(u);
                    if(s.find(v) == s.end()){
                        s.insert(v);
                        res += sz[v.fi][v.se];
                    }   
                }
            }
        }
        return res;
    }
    int Try_Col(int k, vector<vector<char>> &a){
        auto isValid = [&](int n, int m, pii u)->bool {
            return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
        };
        int n = a.size();
        int m = a[0].size();
        int dx[2] = {0, 0};
        int dy[2] = {-1, 1};
        int res = 0;
        set<pii> s;
        for(int i = 0; i < par.size(); i++){
            if(a[i][k] == '.') res++;
            if(a[i][k] == '#'){
                pii x = find({i, k});
                if(s.find(x) == s.end()){
                    res += sz[x.fi][x.se];
                    s.insert({x.fi, x.se});
                }
            } 
            for(int j = 0; j < 2; j++){
                pii u = {i+dx[j], k+dy[j]};
                if(isValid(n, m, u) && a[u.fi][u.se] == '#'){
                    pii v = find(u);
                    if(s.find(v) == s.end()){
                        s.insert(v);
                        res += sz[v.fi][v.se];
                    }   
                }
            }
        }
        return res;
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    FOR(i, 0, n)
        FOR(j, 0, m)
            cin >> a[i][j];
    dsu_2D g(n, m);
    auto isValid = [&](int n, int m, pii u)->bool {
        return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
    };
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    FOR(i, 0, n)
        FOR(j, 0, m){
            if(a[i][j] == '#')
                FOR(k, 0, 4){
                    pii u = {i+dx[k], j+dy[k]};
                    if(isValid(n, m, u) && a[u.fi][u.se] == '#'){
                        g.Union({i, j}, u);
                    }
                }
        }
    int ans = g.Max_opponent();
    FOR(i, 0, n)
        ans = max(ans, g.Try_Row(i, a));
    FOR(i, 0, m)
        ans = max(ans, g.Try_Col(i, a));
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}