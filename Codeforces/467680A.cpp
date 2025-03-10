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

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

int n, m;
int child[maxn*50][26];
bool isEnd[maxn*50];
int cnt = 0;

void add(string s){
    int u = 0;
    for(int i = 0; i < s.size(); i++){
        int k = s[i]-'a';
        if(!child[u][k])
            child[u][k] = ++cnt;
        u = child[u][k];
    }
    isEnd[u] = 1;
}

bool query(string s){
    int u = 0;
    for(int i = 0; i < s.size(); i++){
        int k = s[i]-'a';
        if(!child[u][k])
            return 0;
        u = child[u][k];
    }
    return isEnd[u];
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        add(s);
    }
    int q; cin >> q;
    while(q--){
        string s; cin >> s;
        cout << query(s) << '\n';
    }
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