// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)
 
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n);
    map<int, ll> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]] = 0;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        mp[b[i]] = 0;
    }
    mt19937_64 rng;
    for(auto &it : mp)
        it.se = rng();
    vector<ll> pre1(n+1), pre2(n+1);
    pre1[0] = pre2[0] = 0;
    set<int> s1, s2;
    for(int i = 1; i <= n; i++){
        if(!s1.count(a[i-1])){
            pre1[i] = pre1[i-1]^mp[a[i-1]];
            s1.insert(a[i-1]);
        }
        else pre1[i] = pre1[i-1];
        if(!s2.count(b[i-1])){
            pre2[i] = pre2[i-1]^mp[b[i-1]];
            s2.insert(b[i-1]);
        }
        else pre2[i] = pre2[i-1];
    }
    while(q--){
        int l, r; cin >> l >> r;
        if(pre1[l] == pre2[r])
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