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
ll a[maxn];
pair<ll, ll> st[4*maxn];

pair<ll, ll> merge(pair<ll, ll> x, pair<ll, ll> y){
    pair<ll, ll> ans;
    if(x.fi > y.fi){
        ans.fi = x.fi;
        if(x.se > y.fi)
            ans.se = x.se;
        else
            ans.se = y.fi;
    }
    else{
        ans.fi = y.fi;
        if(y.se > x.fi)
            ans.se = y.se;
        else
            ans.se = x.fi;
    }
    return ans;
}

void update(int id, int l, int r, int pos, ll val){
    if(l > pos || r < pos)
        return;
    if(l == r){
        st[id] = {val, 1};
        return; 
    }
    int mid = (l+r)>>1;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    st[id] = merge(st[id*2], st[id*2+1]);
}

pair<ll, ll> get(int id, int l, int r, int u, int v){
    if(u > r || v < l)
        return {1, 1};
    if(u <= l && v >= r)
        return st[id];
    int mid = (l+r)>>1;
    return merge(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

ll bigMul(ll a, ll b, ll mod){
    if(b == 0) 
        return 0;
    ll t = bigMul(a, b/2, mod);
    if(b%2 == 0)
        return (t+t)%mod;
    return ((t+t)%mod+a%mod)%mod;
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    int q; cin >> q;
    while(q--){
        int tv; cin >> tv;
        if(tv == 0){
            ll x, v; cin >> x >> v;
            update(1, 1, n, x, v);
        }
        else{
            ll l, r, mod; cin >> l >> r >> mod;
            pair<ll, ll> ans = get(1, 1, n, l, r);
            cout << bigMul(ans.fi, ans.se, mod) << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
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