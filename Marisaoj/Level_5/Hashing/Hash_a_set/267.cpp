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
int a[maxn], st[4*maxn];

void build(int id, int l, int r){
    if(l == r){
        st[id] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = min(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if(u > r || v < l) return INT_MAX;
    if(u <= l && v >= r) return st[id];
    int mid = (l+r)>>1;
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void solve(){
    int n, q; cin >> n >> q;
    unordered_set<int> s;
    int se = time(0);
    mt19937 rng(se);
    vi cal(maxn);
    cal[0] = 0;
    for(int i = 1; i < maxn; i++){
        cal[i] = rng();
        while(s.find(cal[i]) != s.end())
            cal[i] = rng();
        s.insert(cal[i]);
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    vi pre(n+1);
    pre[0] = 0;
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i-1]^cal[a[i]];
    vi v(maxn);
    v[0] = 0;
    for(int i = 1; i < maxn; i++)
        v[i] = v[i-1]^cal[i];
    while(q--){
        int l, r; cin >> l >> r;
        int mn = get(1, 1, n, l, r);
        if((pre[r]^pre[l-1]) == (v[mn-1]^v[mn+r-l]))
            cout << "YES\n";
        else
            cout << "NO\n";
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