// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 100006
#define tuple64 tuple<ll, int, int>

bool visited[10];
int indegree[10];
vi adj[10];
vi ans;

void kahn(){
    queue<int> q;
    for(int i = 0; i < 5; i++)
        if(indegree[i] == 0)
            q.push(i);
    while(!q.empty()){
        int u = q.front(); q.pop();
        ans.pb(u);
        for(int v : adj[u]){
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }
    if(ans.size() < 5){
        cout << "impossible";
        return;
    }
    for(int i : ans)
        cout << (char)(i+'A');
}

void solve(){
    for(int i = 0; i < 5; i++){
        string s; cin >> s;
        if(s[1] == '<'){
            adj[s[0]-'A'].pb(s[2]-'A');
            indegree[s[2]-'A']++;
        }
        else{
            adj[s[2]-'A'].pb(s[0]-'A');
            indegree[s[0]-'A']++;
        }
    }
    kahn();
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