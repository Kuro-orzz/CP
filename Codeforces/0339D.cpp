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
#define maxn 200006

int n, q, st[4*maxn];

void update(int id, int l, int r, int pos, int val, int h){
    if(pos < l || pos > r)
        return;
    if(l == r){
        st[id] = val;
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, pos, val, h-1);
    update(id*2+1, mid+1, r, pos, val, h-1);
    if(h&1)//le
        st[id] = st[id*2]|st[id*2+1];
    else//chan
        st[id] = st[id*2]^st[id*2+1];
}

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= (1<<n); i++){
        int x; cin >> x;
        update(1, 1, (1<<n), i, x, n);
    }
    while(q--){
        int p, b; cin >> p >> b;
        update(1, 1, (1<<n), p, b, n);
        cout << st[1] << endl;
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