#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 2e5+1;
ll a[maxn], st[4*maxn], lazy[4*maxn];

void push(int id){
    if(lazy[id]){
        st[id*2] += lazy[id];
        st[id*2+1] += lazy[id];
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
        lazy[id] = 0;
    }
}

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

void update(int id, int l, int r, int u, int v, int val){
    if(u > r || v < l) return;
    if(u <= l && v >= r){
        st[id] += val;
        lazy[id] += val;
        return;
    }
    push(id);
    int mid = (l+r)>>1;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id] = min(st[id*2], st[id*2+1]);
}

ll get(int id, int l, int r, int u, int v){
    if(u > r || v < l) return LLONG_MAX;
    if(u <= l && v >= r) return st[id];
    push(id);
    int mid = (l+r)>>1;
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int q; cin >> q;
    cin.ignore();
    while(q--){
        string s; getline(cin, s);
        stringstream ss(s);
        vi v;
        while(ss >> s)
            v.push_back(stoi(s));
        v[0]++; v[1]++;
        if(v.size() == 3){
            if(v[0] <= v[1])
                update(1, 1, n, v[0], v[1], v[2]);
            else{
                update(1, 1, n, v[0], n, v[2]);
                update(1, 1, n, 1, v[1], v[2]);
            }
        }
        else{
            if(v[0] <= v[1])
                cout << get(1, 1, n, v[0], v[1]) << '\n';
            else
                cout << min(get(1, 1, n, v[0], n), get(1, 1, n, 1, v[1])) << '\n';
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