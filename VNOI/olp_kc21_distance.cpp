#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e5+1; 

int st[4*maxn];
set<int> s;

int get(int id, int l, int r, int u, int v){
    if(u > r || v < l) return INT_MAX;
    if(u <= l && v >= r)
        return st[id];
    int mid = (l+r)>>1;
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void update(int id, int l, int r, int pos, int val){
    if(l > pos || r < pos)
        return;
    if(l == r){
        st[id] = min(abs(*s.lower_bound(val)-val), abs(val-*prev(s.lower_bound(val))));
        return;
    }
    int mid = (l+r)>>1;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    st[id] = min(st[id*2], st[id*2+1]);
}

void update(){}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vi a(n+1), b(m);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    s.insert(all(b));
    for(int i = 1; i <= n; i++)
        update(1, 1, n, i, a[i]);
    while(k--){
        int l, r; cin >> l >> r;
        cout << get(1, 1, n, l, r) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif    
    solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
