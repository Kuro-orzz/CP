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
    // if((int)log2(3)/log2(3) == log2(3)/log2(3))
    //     cout << "yes";
    int n, m; cin >> n >> m;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vi v;
    for(int i = 0; i < n; i++){
        int tmp = a[i];
        bool ch = false;
        if(a[i] == 1){
            v.pb(a[i]);
            continue;
        }
        while(tmp && tmp % 2 == 0){
            tmp /= 2;
            if(tmp == 1){
                v.pb(a[i]);
                ch = true;
                break;
            }
        }
        if(ch) continue;
        tmp = a[i];
        while(tmp && tmp % 3 == 0){
            tmp /= 3;
            if(tmp == 1){
                v.pb(a[i]);
                ch = true;
                break;
            }
        }
        if(ch) continue;
        tmp = a[i];
        while(tmp && tmp % 5 == 0){
            tmp /= 5;
            if(tmp == 1){
                v.pb(a[i]);
                ch = true;
                break;
            }
        }
    }
    sort(all(v));
    while(m--){
        int l, r; cin >> l >> r;
        int ans = upper_bound(all(v), r)-lower_bound(all(v), l);
        cout << ans << '\n';
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
