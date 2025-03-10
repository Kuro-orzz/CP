// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD (int)(1e9+7)
#define N (int)1e7
#define INF ((1ll<<31)-1)
#define bit(mask, i) ((mask>>i)&1)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 1000006

struct Node{
    int ans, open, close;
};

int n, q, a[maxn];
string s;
Node st[4*maxn];

Node cal(Node a, Node b){
    Node res;
    int tmp = min(a.open, b.close);
    res.ans = a.ans+b.ans+tmp*2;
    res.open = a.open+b.open-tmp;
    res.close = a.close+b.close-tmp;
    return res;
}

Node get(int id, int l, int r, int u, int v){
    if(u > r || v < l)
        return {0, 0, 0};
    if(u <= l && v >= r)
        return st[id];
    int mid = (l+r)/2;
    Node t1 = get(id*2, l, mid, u, v);
    Node t2 = get(id*2+1, mid+1, r, u, v);
    return cal(t1, t2);
}

void update(int id, int l, int r, int pos, char c){
    if(pos < l || pos > r)
        return;
    if(l == r){
        st[id] = {0, 0, 0};
        if(c == ')')
            st[id].close = 1;
        else
            st[id].open = 1;
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, pos, c);
    update(id*2+1, mid+1, r, pos, c);
    st[id] = cal(st[id*2], st[id*2+1]);
}

void solve(){
    cin >> s;
    for(int i = 1; i <= s.size(); i++)
        update(1, 1, s.size(), i, s[i-1]);
    cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        Node res = get(1, 1, s.size(), u, v);
        cout << res.ans << endl;
    }
}

int main(){
    fast();
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif    
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}