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
 
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 100006

struct Node{
    int g, cnt;
};

Node st[4*maxn];
vector<pii> query;
unordered_map<int, int> mp;

void compress(){
    set<int> s;
    for(int i = 0; i < query.size(); i++){
        if(query[i].fi == 1)
            s.insert(query[i].se);
    }
    int cnt = 0;
    for(int x : s){
        cnt++;
        mp[x] = cnt;
    }
}

void update(int id, int l, int r, int pos, int val, int t){
    if(pos > r || pos < l)
        return;
    if(l == r){
        st[id].cnt += t;
        if(st[id].cnt)
            st[id].g = val;
        else st[id].g = 0;
        return;
    }
    int mid = (l+r)>>1;
    update(id*2, l, mid, pos, val, t);
    update(id*2+1, mid+1, r, pos, val, t);
    st[id].g = __gcd(st[id*2].g, st[id*2+1].g);
}
 
void solve(){
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int tv, x; cin >> tv >> x;
        query.push_back({tv, x});
    }
    compress();
    for(int i = 0; i < q; i++){
        if(query[i].fi == 1)
            update(1, 1, 1e5, mp[query[i].se], query[i].se, 1);
        else if(query[i].fi == 2)
            update(1, 1, 1e5, mp[query[i].se], query[i].se, -1);
        cout << (st[1].g ? st[1].g : 1) << '\n';
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