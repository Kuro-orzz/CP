#include <bits/stdc++.h> 
#define ll long long
using namespace  std ; 

const int maxn = 1e5+6;
int a[maxn], st[4*maxn];
ll hs[maxn]; 

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

void hashing(){
    mt19937_64 rnd(time(0));
    for(int i = 1; i < maxn; i++)
        hs[i] = rnd();
}

int main(){  
    int n, q; cin >> n >> q;
    hashing();
	for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    ll pre[maxn];
    pre[0] = 0;
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1]^hs[a[i]];
    }
    ll v[maxn];
    v[0] = 0;
    for(int i = 1; i<=maxn; i++)
        v[i] = v[i-1]^hs[i];
    while(q--){
        int l, r; cin >> l >> r;
        int mn = get(1, 1, n, l, r);
        if((pre[r]^pre[l-1]) == (v[mn-1]^v[mn+r-l]))
            cout << "YES\n";
        else cout << "NO\n";
    }
}
