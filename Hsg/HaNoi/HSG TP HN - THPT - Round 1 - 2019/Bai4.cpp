#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<vector<pii>> adj(1e4+6);

int dijkstra(int s, int t){
    vi vis(1e4+6, 0);
    vi d(1e4+6, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        pii t = pq.top(); pq.pop();
        int u = t.se;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto it : adj[u]){
            int v = it.fi;
            int w = it.se;
            if(d[u]+w < d[v]){
                d[v] = d[u]+w;
                pq.push({d[v], v});
            }
        }
    }
    return d[t];
}

void solve(){
    string s; cin >> s;
    map<pii, int> mp;
    pii cur = {0, 0};
    int cnt = 1;
    mp[cur] = cnt++;
    for(int i = 0; i < s.size(); i++){
        pii prev = cur;
        if(s[i] == 'D') cur.fi += 1;
        else if(s[i] == 'T') cur.fi -= 1;
        else if(s[i] == 'B') cur.se += 1;
        else cur.se -= 1;
        if(!mp.count(cur))
            mp[cur] = cnt++;
        adj[mp[prev]].push_back({mp[cur], 1});
        adj[mp[cur]].push_back({mp[prev], 1});
    }
    cout << dijkstra(1, mp[cur]);
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
