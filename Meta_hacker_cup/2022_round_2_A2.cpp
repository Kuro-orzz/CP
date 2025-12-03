/*  
    https://web.facebook.com/codingcompetitions/hacker-cup/2022/round-2/problems/A2   
*/

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e6+5;
ll st[4*maxn], hs[maxn];
unordered_set<ll> s;

ll get(int id, int l, int r, int u, int v){
    if(u > r || v < l) return 0;
    if(u <= l && v >= r) return st[id];
    int mid = (l+r)>>1;
    return get(id*2, l, mid, u, v)+get(id*2+1, mid+1, r, u, v);
}

void update(int id, int l, int r, int pos, ll val){
    if(pos > r || pos < l) return;
    if(l == r){
        st[id] = val;
        return;
    }
    int mid = (l+r)>>1;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    st[id] = st[id*2]+st[id*2+1];
}

void hashing(){
    mt19937_64 rng(time(0));
    for(int i = 0; i < maxn; i++){
        hs[i] = rng();
        s.insert(hs[i]);
    }
}

void solve(int t){
    int n; cin >> n;
    s.clear();
    hashing();
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        update(1, 1, n, i, hs[x]);
    }
    int q; cin >> q;
    int ans = 0;
    while(q--){
        int tv, x, y; cin >> tv >> x >> y;
        if(tv == 1)
            update(1, 1, n, x, hs[y]);
        else{
            if(x == y){
                ans++;
                continue;
            }
            if((y-x) % 2) continue;
            int mid = (x+y)>>1;
            ll l = get(1, 1, n, x, mid);
            ll r = get(1, 1, n, mid+1, y);
            if(s.find(l-r) != s.end()){
                ans++;
                continue;
            }
            mid--;
            l = get(1, 1, n, x, mid);
            r = get(1, 1, n, mid+1, y);
            if(s.find(r-l) != s.end()){
                ans++;
                continue;
            }
        }
    }
    cout << "Case #" << t << ": " << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int t; cin >> t;
    int cnt = 1;
    while(t--){
        solve(cnt);
        cnt++;
    }
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
