#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e5+6;
int st[4*maxn], lazy[4*maxn];

void push(int id, int sz){
    if(lazy[id]){
        if(lazy[id]%2){
            st[id*2] = sz-sz/2-st[id*2];
            st[id*2+1] = sz/2-st[id*2+1];
            lazy[id*2]++;
            lazy[id*2+1]++;
            lazy[id]--;
        }        
    }
}
int get(int id, int l, int r, int u, int v){
    if(u > r || v < l) return 0;
    if(u <= l && v >= r) return st[id];
    int mid = (l+r)>>1;
    push(id, r-l+1);
    return get(id*2, l, mid, u, v)+get(id*2+1, mid+1, r, u, v);
}
void update(int id, int l, int r, int u, int v){
    if(u > r || v < l) return;
    if(u <= l && v >= r){
        st[id] = r-l+1-st[id];
        lazy[id]++;
        return;
    }
    push(id, r-l+1);
    int mid = (l+r)>>1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id] = st[id*2]+st[id*2+1];
}

void solve(){
    int n, m; cin >> n >> m;
    while(m--){
        int tv, l, r; cin >> tv >> l >> r;
        if(tv == 0) update(1, 1, n, l, r);
        else cout << get(1, 1, n, l, r) << '\n';
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
