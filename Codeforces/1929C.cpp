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
#define N 1000000

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second

ll sol(ll n, ll k){
    return (n+k-1)/(k-1);
}

void solve(){
    ll k, x, a; cin >> k >> x >> a;
    ll tmp = 0;
    bool ok = true;
    for(int i = 0; ok && i < x; i++){
        ll v = sol(tmp, k);
        if(v == 0)
            tmp += 1;
        else
            tmp += v;
        if(tmp > a)
            ok = false;
    }
    if(k*(a-tmp) > a)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    
}

int main(){
    fast();
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif    
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
